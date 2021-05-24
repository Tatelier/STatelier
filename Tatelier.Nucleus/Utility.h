#pragma once

#include <functional>
#include <string>
#include <vector>

/**
 * @brief �����G���R�[�h���
 *
 */
enum class EncodingType {
	/**
	 * @brief �s��
	 *
	 */
	Unknown,
	Unicode,
	ShiftJIS,
	EUC,
	ASCII,
	UTF8
};

/**
 * @brief �����񂪑O����v���Ă��邩�𔻒肷��
 *
 * @param s [in] �Ώۂ̕�����
 * @param suffix [in] ��v������
 * @return true:��v, false:�s��v
 */
bool ttleStartWith(const std::string& s, const std::string& prefix);

/**
 * @brief �����񂪌����v���Ă��邩�𔻒肷��
 *
 * @param s [in] �Ώۂ̕�����
 * @param suffix [in] ��v������
 * @return true:��v, false:�s��v
 */
bool ttleEndWith(const std::string& s, const std::string& suffix);

int32_t ttleEndWithIndex(const std::string& s, const std::string& suffixSplit);

/**
 * @brief �w�肵���f�B���N�g�������T�u�f�B���N�g���܂ŒT�����A�t�@�C���ꗗ���擾����
 *
 * @param [in] folderPath �T���f�B���N�g���̃p�X
 * @param [out] ���ʃt�@�C���ꗗ
 * @param [in] �t�B���^�֐�
 */
bool ttleGetFileNamesRecursive(const std::string& folderPath, std::vector<std::string>* file_names, std::function<bool(const std::string&)> filter);

/**
 * @brief UTF8�̕������SJIS�ɕϊ�����
 *
 * @param srcUTF8 [in] UTF8�̕�����
 * @return std::string SJIS�̕�����
 */
std::string ttleUTF8toSjis(const std::string& srcUTF8);

/**
 * @brief ������𔻒肵��SJIS�ɕϊ�����
 *
 * @param text [in] ������
 * @return std::string SJIS�̕�����
 */
std::string ttleConvertToSjis(const std::string& text);

/**
 * @brief ������̕����G���R�[�h���擾����
 *
 * @param text [in] ������
 * @return EncodingType �����G���R�[�h
 */
EncodingType ttleGetEncodingType(const std::string& text);