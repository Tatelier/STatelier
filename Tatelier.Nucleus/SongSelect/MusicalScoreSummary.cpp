#include "MusicalScoreSummary.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <regex>

#include "../Utility.h"


using namespace ttle::io;


#define MAP_ITEM(name, readFunc) { name, std::bind(readFunc, std::placeholders::_1, std::placeholders::_2) }

namespace Tatelier::SongSelect {

	std::unordered_map<std::string, std::function<TLRESULT(MusicalScoreSummary*, const std::string&)>> MusicalScoreSummary::funcMap {
		MAP_ITEM("TITLE", &MusicalScoreSummary::SetReadTitle),
		MAP_ITEM("WAVE", &MusicalScoreSummary::SetReadWaveFilePath),
		MAP_ITEM("GENRE", &MusicalScoreSummary::SetReadGenreNameList),
	};

	MusicalScoreSummary::MusicalScoreSummary()
	{

	}

	TLRESULT MusicalScoreSummary::Init(const std::string& rootFolder, const std::string& relativeFilePath)
	{
		std::string path;
		if (Path::Combine(rootFolder, relativeFilePath, &path) != TL_SUCCESS) {
			// TODO: エラー処理
		}

		filePathRelative = relativeFilePath;

		return Init(path);
	}

	const std::string& MusicalScoreSummary::GetTitle()
	{
		return title;
	}

	TLRESULT MusicalScoreSummary::SetTitle(const std::string& title)
	{
		this->title = title;

		return TL_SUCCESS;
	}

	const std::string& MusicalScoreSummary::GetWaveFilePath()
	{
		return waveFilePath;
	}

	TLRESULT MusicalScoreSummary::SetWaveFilePath(const std::string& waveFilePath)
	{
		this->waveFilePath = waveFilePath;
		return TL_SUCCESS;
	}

	const std::vector<std::string>& MusicalScoreSummary::GetGenreNameList()
	{
		return genreNameList;
	}

	TLRESULT MusicalScoreSummary::SetGenreNameList(const std::vector<std::string>& genreNameList)
	{
		this->genreNameList = genreNameList;

		return TL_SUCCESS;
	}

	TLRESULT MusicalScoreSummary::SetReadTitle(const std::string& arg)
	{
		this->title = arg;

		return TL_SUCCESS;
	}

	TLRESULT MusicalScoreSummary::SetReadWaveFilePath(const std::string& arg)
	{
		this->waveFilePath = arg;

		return TL_SUCCESS;
	}

	TLRESULT MusicalScoreSummary::SetReadGenreNameList(const std::string& arg)
	{
		if (ttle::string::Split(arg, "|", &genreNameList) != TL_SUCCESS)
		{
			// TODO: エラー処理
		}

		return TL_SUCCESS;
	}

	TLRESULT MusicalScoreSummary::Init(const std::string& filePath)
	{
		std::string text;

		std::vector<std::string> lines;

		if (File::ReadAllLines(filePath, &lines) != TL_SUCCESS)
		{
			// TODO: エラー処理
		}

		std::regex regex(R"((\S+):(.+))");
		std::smatch matches;

		for (auto& line : lines) {
			if (std::regex_match(line, matches, regex)) {
				if (funcMap.find(matches[1]) != funcMap.end()) {
					funcMap[matches[1]](this, matches[2]);
				}
			}
		}

		EncodingType type = ttleGetEncodingType(text);

		return TL_SUCCESS;
	}
}