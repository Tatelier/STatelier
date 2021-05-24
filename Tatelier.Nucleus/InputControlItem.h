#pragma once

#include <cstdint>

#include "IInputControlItem.h"

namespace Tatelier {

	class Input;

	/**
	 * @brief 入力コントロールアイテムクラス
	 */
	class InputControlItem : public IInputControlItem {
	public:
		/**
		 * @brief キーの入力数を取得する
		 *
		 * @param [in] key キー
		 * @return 0: 未入力, -1: 離れた直後, 1以上: 入力数
		 */
		virtual int32_t GetCount(int key);

		/**
		 * @brief キーを押下中かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 押下中, false: 未押下
		 */
		virtual bool GetKey(int key);

		/**
		 * @brief キーを離した直後かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 離した直後, false: 直後ではない
		 */
		virtual bool GetKeyUp(int key);

		/**
		 * @brief キーを押下した直後かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 押下した直後, false: 直後ではない
		 */
		virtual bool GetKeyDown(int key);

		/**
		 * @brief 有効かどうかを取得する
		 *
		 * @return true: 有効, false: 無効
		 */
		bool IsEnabled();

		/**
		 * @brief 有効かどうかを設定する
		 * 
		 * @param [in] enabled true: 有効, false: 無効
		 */
		void SetEnbaled(bool enable);

		/**
		 * @brief コンストラクタ
		 */
		InputControlItem();

		/**
		 * @brief デストラクタ
		 */
		virtual ~InputControlItem();
	protected:
		Input* m_pInputControl;
	private:
		bool m_enabled;
	};
}