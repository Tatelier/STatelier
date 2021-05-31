#pragma once

#include <cstdint>

#include <functional>
#include <string>
#include <vector>
#include "ttle.h"

using namespace ttle;

namespace Tatelier {

	/**
	 * @brief 文字エンコード種別
	 *
	 */
	enum class EncodingType {
		/**
		 * @brief 不明
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
	 * @brief UTF8の文字列をSJISに変換する
	 *
	 * @param srcUTF8 [in] UTF8の文字列
	 * @return std::string SJISの文字列
	 */
	std::string ttleUTF8toSjis(const std::string& srcUTF8);

	/**
	 * @brief 文字列を判定してSJISに変換する
	 *
	 * @param text [in] 文字列
	 * @return std::string SJISの文字列
	 */
	std::string ttleConvertToSjis(const std::string& text);

	/**
	 * @brief 文字列の文字エンコードを取得する
	 *
	 * @param text [in] 文字列
	 * @return EncodingType 文字エンコード
	 */
	EncodingType ttleGetEncodingType(const std::string& text);

	/**
	* @brief 文字列を置換する
	*
	* @param text [in] 文字列
	* @return EncodingType 文字エンコード
	*/
	std::string ttleReplaceString(const std::string& source, const std::string& oldString, const std::string& newString);

}