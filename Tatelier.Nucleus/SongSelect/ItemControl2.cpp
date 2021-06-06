#include "ItemControl2.h"

#include <filesystem>

#include "../Utility.h"
#include "MusicalScoreSummary.h"

namespace Tatelier::SongSelect {

	ItemControl2::ItemControl2()
	{
	}

	ItemControl2::~ItemControl2()
	{
		for (auto& item : scoreList) {
			delete item;
		}
	}

	uint32_t ItemControl2::Init(const std::string& scoreFolderPath)
	{
		using namespace ttle;
		using namespace ttle::io;

		std::string rootRootFolderPath;

		if (Path::Combine(scoreFolderPath, rootFolderName, "", &rootRootFolderPath) != TL_SUCCESS) {
			// TODO: エラー処理
		}

		std::vector<std::string> scoreFileList;

		if (Dictionary::GetFileListRecursive(rootRootFolderPath, &scoreFileList, [this](std::string a) {
			return string::EndWithIndex(a, searchFilterExtensions) > 0;
		}) != TL_SUCCESS) {
			// TODO: エラー処理
		}

		if (scoreFileList.size() > 0) {
			for (auto& item : scoreFileList) {				

				if (ttle::string::Replace(item, rootRootFolderPath, "", &item) != TL_SUCCESS)
				{
					// TODO: エラー処理
				}
				auto* summary = new MusicalScoreSummary();
				summary->Init(rootRootFolderPath, item);
				scoreList.push_back(summary);
			}
		}

		return 0;
	}
}