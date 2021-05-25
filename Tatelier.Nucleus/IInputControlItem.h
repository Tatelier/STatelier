#pragma once

#include <cstdint>

namespace Tatelier {
	/**
	 * @brief 入力アイテムインターフェース
	 */
	class IInputControlItem {
	public:
		/**
		 * @brief 有効かどうかを取得する
		 * @return true: 有効, false: 無効
		 */
		virtual bool IsEnabled() = 0;

		/**
		 * @brief 有効かどうかを設定する
		 * 
		 * @param [in] enabled true: 有効, false: 無効
		 */
		virtual void SetEnabled(bool enabled) = 0;

        /**
		 * @brief キーの入力数を取得する
		 *
		 * @param [in] key キー
		 * @return 0: 未入力, -1: 離れた直後, 1以上: 入力数
		 */
        virtual int32_t GetCount(int key) = 0;

        /**
		 * @brief キーを押下中かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 押下中, false: 未押下
		 */
		virtual bool GetKey(int key) = 0;

        /**
		 * @brief キーを離した直後かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 離した直後, false: 直後ではない
		 */
		virtual bool GetKeyUp(int key) = 0;

        /**
		 * @brief キーを押下した直後かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 押下した直後, false: 直後ではない
		 */
		virtual bool GetKeyDown(int key) = 0;
	};
}