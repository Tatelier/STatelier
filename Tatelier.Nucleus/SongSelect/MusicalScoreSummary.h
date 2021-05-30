#pragma once

#include <string>

#include <functional>
#include <unordered_map>

#include "../ttle.h"

using namespace ttle;

namespace Tatelier::SongSelect {

	class MusicalScoreSummary {
	public:
		static std::unordered_map<std::string, std::function<TLRESULT(MusicalScoreSummary*, const std::string&)>> map;
		MusicalScoreSummary(const std::string& rootFolder, const std::string& relativeFilePath);

		const std::string& GetTitle();
		TLRESULT SetTitle(const std::string& title);

	private:
		std::string title;

		TLRESULT SetReadTitle(const std::string& arg);

		MusicalScoreSummary(const std::string& filePath);
	};
}