#include "ttle.h"

#include <cstdint>

#include <vector>
#include <iterator>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace ttle {
	namespace text {
		TLRESULT Encoding::GetEncoding(std::string name, Encoding* encoding)
		{
			// TODO: nameでEncodingの有無を調べて、それを返す。

			return 0x80000001;
		}
	}
	namespace io {
		TLRESULT File::ReadAllLines(const std::string& filePath, std::vector<std::string>* lines)
		{
			const TLRESULT ERROR_NOT_FOUND = 0x80000001;

			std::ifstream ifs(filePath);

			if (!ifs.is_open()) {
				return ERROR_NOT_FOUND;
			}

			std::string buffer;

			while (!ifs.eof()) {
				std::getline(ifs, buffer);
				lines->push_back(buffer);
			}

			return TL_SUCCESS;
		}
		TLRESULT File::ReadAllText(const std::string& filePath, std::string* text)
		{
			const TLRESULT ERROR_NOT_FOUND = 0x80000001;

			std::ostringstream ss;
			std::ifstream ifs(filePath);
			if (!ifs.is_open()) {
				return ERROR_NOT_FOUND;
			}

			*text = std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());

			return TL_SUCCESS;
		}

		TLRESULT Path::Combine(const std::string& path1
			, const std::string& path2
			, std::string* result)
		{
			using namespace std::filesystem;

			path path;

			path /= path1;
			path /= path2;

			*result = path.string();

			return TL_SUCCESS;
		}

		TLRESULT Path::Combine(const std::string& path1
			, const std::string& path2
			, const std::string& path3
			, std::string* result)
		{
			using namespace std::filesystem;

			path path;

			path /= path1;
			path /= path2;
			path /= path3;

			*result = path.string();

			return TL_SUCCESS;
		}

		TLRESULT Path::Combine(const std::string& path1
			, const std::string& path2
			, const std::string& path3
			, const std::string& path4
			, std::string* result)
		{
			using namespace std::filesystem;

			path path;

			path /= path1;
			path /= path2;
			path /= path3;
			path /= path4;

			*result = path.string();

			return TL_SUCCESS;
		}
		TLRESULT Dictionary::GetFileListRecursive(const std::string& folderPath, std::vector<std::string>* fileNameList, std::function<bool(const std::string&)> filter)
		{
			const TLRESULT ERROR = 0x80000000;
			const TLRESULT ERROR_NOT_FOUND = 0x80000001;

			if (!std::filesystem::exists(folderPath))
			{
				return ERROR_NOT_FOUND;
			}

			std::filesystem::recursive_directory_iterator iter(folderPath), end;
			std::error_code err;

			for (; iter != end && !err; iter.increment(err)) {
				const std::filesystem::directory_entry entry = *iter;

				std::string path = entry.path().string();

				if (filter(path)) {
					fileNameList->push_back(path);
				}
			}

			if (err) {
				return ERROR;
			}

			return TL_SUCCESS;
		}
	}
}

namespace ttle::text::EncodingItem {
	TLRESULT SJIS::GetString(const std::string& source, std::string* destination)
	{
		// TODO: 未実装
		return 0x80000000;
	}
}

bool ttle::string::StartWith(const std::string& s, const std::string& prefix)
{
	auto size = prefix.size();
	if (s.size() < size)
		return false;
	return std::equal(std::begin(prefix), std::end(prefix), std::begin(s));
}

int32_t ttle::string::StartWithIndex(const std::string& text, const std::string& suffixSplit)
{
	std::stringstream ss{ suffixSplit };
	std::string buf;

	for (int i = 1; std::getline(ss, buf, '|'); i++) {
		if (StartWith(text, buf)) {
			return i;
		}
	}

	return -1;
}

bool ttle::string::EndWith(const std::string& s, const std::string& suffix)
{
	if (s.size() < suffix.size()) {
		return false;
	}
	return std::equal(std::rbegin(suffix), std::rend(suffix), std::rbegin(s));
}

int32_t ttle::string::EndWithIndex(const std::string& text, const std::string& suffixSplit)
{
	std::stringstream ss{ suffixSplit };
	std::string buf;

	for (int i = 1; std::getline(ss, buf, '|'); i++) {
		if (EndWith(text, buf)) {
			return i;
		}
	}

	return -1;
}
