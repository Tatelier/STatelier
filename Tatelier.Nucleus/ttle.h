#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <functional>

namespace ttle {

	typedef unsigned int TLRESULT;

	constexpr TLRESULT TL_SUCCESS = 0;


	namespace string {

		/**
		 * @brief �����񂪑O����v���Ă��邩���肷��B
		 * @param text �����Ώ�
		 * @param suffix �������镶����
		 * @return true: ��v, false: �s��v
		*/
		bool StartWith(const std::string& text, const std::string& prefix);

		/**
		 * @brief �����񂪌����v���Ă��邩���肵�A��v�ӏ��̐擪�v�f�ԍ���Ԃ��B
		 * @param text �����Ώ�
		 * @param suffixSplit �������镶����
		 * @return >= 0: ��v�ӏ��̐擪�v�f�ԍ�, -1: �s��v
		*/
		int32_t StartWithIndex(const std::string& text, const std::string& suffixSplit);

		/**
		 * @brief �����񂪌����v���Ă��邩���肷��B
		 * @param text �����Ώ�
		 * @param suffix �������镶����
		 * @return true: ��v, false: �s��v
		*/
		bool EndWith(const std::string& text, const std::string& suffix);

		/**
		 * @brief �����񂪌����v���Ă��邩���肵�A��v�ӏ��̐擪�v�f�ԍ���Ԃ��B
		 * @param text �����Ώ�
		 * @param suffixSplit �������镶���� ��) *.tja|*.tlscore
		 * @return >= 0: ��v�ӏ��̐擪�v�f�ԍ�, -1: �s��v
		*/
		int32_t EndWithIndex(const std::string& text, const std::string& suffixSplit);

		/**
		* @brief �������u������
		* @todo �R�����g�����Ə���
		*/
		TLRESULT Replace(const std::string& text, const std::string& oldValue, const std::string& newValue, std::string* result);
	
		/**
		* @brief ������𕪊�����
		* @todo �R�����g�����Ə���
		*/
		TLRESULT Split(const std::string& text, const std::string& separator, std::vector<std::string>* result);
	}

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
			 * @brief �w�肵���f�B���N�g�������T�u�f�B���N�g���܂ŒT�����A�t�@�C���ꗗ���擾����
			 *
			 * @param [in] folderPath �T���f�B���N�g���̃p�X
			 * @param [out] ���ʃt�@�C���ꗗ
			 * @param [in] �t�B���^�֐�
			 *
			 * @return TL_SUCCESS: ����
			 */
			static TLRESULT GetFileListRecursive(const std::string& folderPath, std::vector<std::string>* fileNameList, std::function<bool(const std::string&)> filter);
		};
	}
}