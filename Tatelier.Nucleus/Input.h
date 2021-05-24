#pragma once
#include <cstdint>

#include "DxLib.h"

namespace Tatelier {

	/**
	 * @brief キー入力クラス ※シングルトン
	 */
	class Input {
	public:
		/**
		 * @brief シングルトンインスタンスを取得する
		 * 
		 * @return インスタンス
		 */
		static Input& GetInstance();

		/**
		 * @brief キーの入力数を取得する
		 *
		 * @param [in] key キー
		 * @return 0: 未入力, -1: 離れた直後, 1以上: 入力数
		 */
		int32_t GetCount(int key);

		/**
		 * @brief キーを押下中かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 押下中, false: 未押下
		 */
		bool GetKey(int key);

		/**
		 * @brief キーを離した直後かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 離した直後, false: 直後ではない
		 */
		bool GetKeyUp(int key);

		/**
		 * @brief キーを押下した直後かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 押下した直後, false: 直後ではない
		 */
		bool GetKeyDown(int key);

		/**
		 * @brief 更新処理
		 *
		 * @remark メインループでコールすること
		 */
		void Update();
	private:
		const static int32_t BytesLen = 256;

		char bytes[BytesLen];
		int32_t cntBytes[BytesLen];

		Input() { }
		Input(const Input& instance) { }
	};
}