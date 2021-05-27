#include "ItemControl2.h"

#include <filesystem>

#include "../Utility.h"
#include "MusicalScoreSummary.h"

namespace Tatelier::SongSelect {

	ItemControl2::ItemControl2()
	{
	}

	uint32_t ItemControl2::Init(const std::string& scoreFolderPath)
	{
		std::filesystem::path scoreRootFolder;

		scoreRootFolder /= scoreFolderPath;
		scoreRootFolder /= rootFolderName;
		scoreRootFolder /= "";

		std::vector<std::string> scoreFileList;

		if (ttleGetFileNamesRecursive(scoreRootFolder.string(), &scoreFileList, [this](std::string a) {
			return ttleEndWithIndex(a, searchFilterExtensions) > 0;
		}) != TL_SUCCESS) {
			// TODO: ƒGƒ‰[ˆ—
		}

		if (scoreFileList.size() > 0) {
			for (auto& item : scoreFileList) {
							
				item = ttleReplaceString(item, scoreRootFolder.string(), "");
				auto* summary = new MusicalScoreSummary(scoreRootFolder.string(), item);
				delete summary;
			}
		}

		return 0;
	}
}