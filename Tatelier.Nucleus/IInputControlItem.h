#pragma once

#include <cstdint>

namespace Tatelier {
	/**
	 * @brief 入力アイテムインターフェース
	 */
	class IInputControlItem {
	public:
		virtual bool IsEnabled() = 0;
		virtual void SetEnabled() = 0;

		virtual int32_t GetCount(int key) = 0;
		virtual bool GetKey(int key) = 0;
		virtual bool GetKeyUp(int key) = 0;
		virtual bool GetKeyDown(int key) = 0;
	};
}