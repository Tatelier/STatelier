#pragma once

#include "../IInputControlItem.h"

namespace Tatelier {
	class Input;
}

namespace Tatelier::SongSelect {


	class InputControlItemSongSelect : public IInputControlItem {
	public:
		/**
		 * @brief 1つ前ボタン
		 */
		const static int Prev = -1;


		/**
		 * @brief キーの入力数を取得する
		 *
		 * @param [in] key キー
		 * @return 0: 未入力, -1: 離れた直後, 1以上: 入力数
		 */
		int32_t GetCount(int key) override;

		/**
		 * @brief キーを押下中かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 押下中, false: 未押下
		 */
		bool GetKey(int key) override;

		/**
		 * @brief キーを離した直後かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 離した直後, false: 直後ではない
		 */
		bool GetKeyUp(int key) override;

		/**
		 * @brief キーを押下した直後かどうかを取得する
		 *
		 * @param [in] key キー
		 * @return true: 押下した直後, false: 直後ではない
		 */
		bool GetKeyDown(int key) override;
		InputControlItemSongSelect();
		~InputControlItemSongSelect();
	private:
		::Tatelier::Input* m_pInputControl;
	};

}
