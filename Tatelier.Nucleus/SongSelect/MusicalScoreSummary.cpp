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
		MAP_ITEM("WAVE", &MusicalScoreSummary::SetWaveFilePath),
	};

	MusicalScoreSummary::MusicalScoreSummary(const std::string& rootFolder, const std::string& relativeFilePath)
	{
		std::string path;
		if (Path::Combine(rootFolder, relativeFilePath, &path) != TL_SUCCESS) {
			// TODO: エラー処理
		}

		filePathRelative = relativeFilePath;
		MusicalScoreSummary::MusicalScoreSummary(path);
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

	MusicalScoreSummary::MusicalScoreSummary(const std::string& filePath)
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
	}
}