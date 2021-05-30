#pragma once

#include <cstdint>
#include <string>
#include <vector>

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
	}
}