#pragma once

#include <iostream>
#include <sstream>

namespace Hjson {
	class Value;
}

namespace HjsonEx {

	Hjson::Value Load(const std::string& path);

	int EQv(const Hjson::Value& hj_value, const std::string& key, Hjson::Value* result);
	int EQv(const Hjson::Value& hj_value, const std::string& key, Hjson::Value* result, const Hjson::Value& failure);

	int EQa(const Hjson::Value& hj_value, const std::string& key, Hjson::Value* result);
	int EQa(const Hjson::Value& hj_value, const std::string& key, Hjson::Value* result, const Hjson::Value& failure);

	/**
		 * @brief ��������擾
		 */
	int EQs(const Hjson::Value& hj_value, const std::string& key, std::string* result);
	int EQs(const Hjson::Value& hj_value, const std::string& key, std::string* result, const std::string& failure);

	/**
		 * @brief int32�^�̒l���擾 �����s����0
		 */
	int EQi(const Hjson::Value& hj_value, const std::string& key, int32_t* result);

	/**
		 * @brief int32�^�̒l���擾
		 */
	int EQi(const Hjson::Value& hj_value, const std::string& key, int32_t* result, const int32_t& failure);
}