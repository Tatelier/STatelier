#include "MusicalScoreSummary.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <regex>

#include "../Utility.h"


using namespace ttle::io;

namespace Tatelier::SongSelect {

	std::unordered_map<std::string, std::function<TLRESULT(MusicalScoreSummary*, const std::string&)>> MusicalScoreSummary::map {
		{ "TITLE", std::bind(&MusicalScoreSummary::SetReadTitle, std::placeholders::_1, std::placeholders::_2) }
	};

	MusicalScoreSummary::MusicalScoreSummary(const std::string& rootFolder, const std::string& relativeFilePath)
	{
		std::string path;
		if (Path::Combine(rootFolder, relativeFilePath, &path) != TL_SUCCESS) {

		}
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

	TLRESULT MusicalScoreSummary::SetReadTitle(const std::string& arg)
	{
		this->title = arg;

		return TL_SUCCESS;
	}

	MusicalScoreSummary::MusicalScoreSummary(const std::string& filePath)
	{
		std::string text;

		std::vector<std::string> lines;

		if (File::ReadAllLines(filePath, &lines) != TL_SUCCESS)
		{
			// TODO: ÉGÉâÅ[èàóù
		}

		std::regex regex(R"((\S+):(.+))");
		std::smatch matches;

		for (auto& line : lines) {
			if (std::regex_match(line, matches, regex)) {
				if (map.find(matches[1]) != map.end()) {
					map[matches[1]](this, matches[2]);
				}
			}
		}

		EncodingType type = ttleGetEncodingType(text);
	}
}