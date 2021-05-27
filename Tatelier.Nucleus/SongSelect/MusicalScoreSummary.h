#pragma once

#include <string>

namespace Tatelier::SongSelect {

	class MusicalScoreSummary {
	public:
		MusicalScoreSummary(const std::string& rootFolder, const std::string& relativeFilePath);
	private:
		MusicalScoreSummary(const std::string& filePath);
	};
}