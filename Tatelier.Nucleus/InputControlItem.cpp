#include "InputControlItem.h"

#include "Input.h"

namespace Tatelier {

	int32_t InputControlItem::GetCount(int keyCode)
	{
		if (!IsEnabled()) {
			return 0;
		}

		return m_pInputControl->GetCount(keyCode);
	}

	bool InputControlItem::GetKey(int keyCode)
	{
		if (!IsEnabled()) {
			return false;
		}
		return m_pInputControl->GetKey(keyCode);
	}

	bool InputControlItem::GetKeyDown(int keyCode)
	{
		if (!IsEnabled()) {
			return false;
		}
		return m_pInputControl->GetKeyDown(keyCode);
	}

	bool InputControlItem::GetKeyUp(int keyCode)
	{
		if (!IsEnabled()) {
			return false;
		}
		return m_pInputControl->GetKeyUp(keyCode);
	}

	bool InputControlItem::IsEnabled()
	{
		return m_enabled;
	}

	void InputControlItem::SetEnbaled(bool enabled)
	{
		m_enabled = enabled;
	}

	InputControlItem::InputControlItem()
	{
		m_pInputControl = &Input::GetInstance();
	}

	InputControlItem::~InputControlItem()
	{
	}
}