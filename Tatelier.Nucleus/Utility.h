#pragma once

#include <cstdint>

#include <functional>
#include <string>
#include <vector>
#include "ttle.h"

using namespace ttle;

namespace Tatelier {

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

	/**
	* @brief �������u������
	*
	* @param text [in] ������
	* @return EncodingType �����G���R�[�h
	*/
	std::string ttleReplaceString(const std::string& source, const std::string& oldString, const std::string& newString);

}