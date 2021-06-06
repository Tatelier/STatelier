#pragma once

#include <cstdint>

#include <iostream>
#include <sstream>

#include "hjson.h"

namespace HjsonEx {

	constexpr int32_t SUCCESS = 1;

	Hjson::Value Load(const std::string& path);

	int32_t EQv(const Hjson::Value& hj_value, const std::string& key, Hjson::Value* result);
	int32_t EQv(const Hjson::Value& hj_value, const std::string& key, Hjson::Value* result, const Hjson::Value& failure);

	int32_t EQa(const Hjson::Value& hj_value, const std::string& key, Hjson::Value* result);
	int32_t EQa(const Hjson::Value& hj_value, const std::string& key, Hjson::Value* result, const Hjson::Value& failure);

	/**
	* @brief 文字列を取得
	*/
	int32_t EQs(const Hjson::Value& hj_value, const std::string& key, std::string* result);
	int32_t EQs(const Hjson::Value& hj_value, const std::string& key, std::string* result, const std::string& failure);

	/**
	* @brief int32型の値を取得 ※失敗時は0
	*/
	int32_t EQi(const Hjson::Value& hj_value, const std::string& key, int32_t* result);

	/**
	* @brief int32型の値を取得
	*/
	int32_t EQi(const Hjson::Value& hj_value, const std::string& key, int32_t* result, const int32_t& failure);
}