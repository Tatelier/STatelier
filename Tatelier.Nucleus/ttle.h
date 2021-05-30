#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <functional>

namespace ttle {

	typedef unsigned int TLRESULT;

	constexpr TLRESULT TL_SUCCESS = 0;

	namespace text {
		class Encoding {
		public:
			static TLRESULT GetEncoding(std::string name, Encoding* encoding);
			virtual TLRESULT GetString(const std::string& source, std::string* destination) = 0;
		private:
		};
		
		namespace EncodingItem {
			class SJIS : public Encoding {
			public:
				virtual TLRESULT GetString(const std::string& source, std::string* destination) override;
			};
		}
	}

	namespace io {
		class Path {
		public:
			static TLRESULT Combine(const std::string& path1
				, const std::string& path2
				, std::string* result);

			static TLRESULT Combine(const std::string& path1
				, const std::string& path2
				, const std::string& path3
				, std::string* result);

			static TLRESULT Combine(const std::string& path1
				, const std::string& path2
				, const std::string& path3
				, const std::string& path4
				, std::string* result);
		};

		class File {
		public:
			static TLRESULT ReadAllLines(const std::string& filePath, std::vector<std::string>* lines);
			static TLRESULT ReadAllText(const std::string& filePath, std::string* text);
		};

		class Dictionary {
		public:
			/**
			 * @brief 指定したディレクトリ内をサブディレクトリまで探索し、ファイル一覧を取得する
			 *
			 * @param [in] folderPath 探索ディレクトリのパス
			 * @param [out] 結果ファイル一覧
			 * @param [in] フィルタ関数
			 *
			 * @return TL_SUCCESS: 成功
			 */
			static TLRESULT GetFileListRecursive(const std::string& folderPath, std::vector<std::string>* fileNameList, std::function<bool(const std::string&)> filter);
		};
	}
}