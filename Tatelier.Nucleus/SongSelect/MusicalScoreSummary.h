#pragma once

#include <string>

#include <functional>
#include <unordered_map>

#include "../ttle.h"

using namespace ttle;

namespace Tatelier::SongSelect {

	class MusicalScoreSummary {
	public:
		MusicalScoreSummary(const std::string& rootFolder, const std::string& relativeFilePath);

		const std::string& GetTitle();
		TLRESULT SetTitle(const std::string& title);

		const std::string& GetWaveFilePath();
		TLRESULT SetWaveFilePath(const std::string& waveFilePath);
	private:
		static std::unordered_map<std::string, std::function<TLRESULT(MusicalScoreSummary*, const std::string&)>> funcMap;
		std::string filePathRelative;
		std::string title;
		std::string waveFilePath;

		TLRESULT SetReadTitle(const std::string& arg);
		TLRESULT SetReadWaveFilePath(const std::string& arg);

		MusicalScoreSummary(const std::string& filePath);
	};
}