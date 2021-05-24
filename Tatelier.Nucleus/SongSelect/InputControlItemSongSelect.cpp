#include "InputControlItemSongSelect.h"

#include "../Input.h"


namespace Tatelier::SongSelect {

	int32_t InputControlItemSongSelect::GetCount(int key)
	{
		return m_pInputControl->GetKey(key);
	}

	bool InputControlItemSongSelect::GetKey(int keyCode)
	{
		if (!IsEnabled()) {
			return false;
		}

		switch (keyCode) {
		case Prev:
			return m_pInputControl->GetKey(KEY_INPUT_L) || m_pInputControl->GetKey(KEY_INPUT_UP);
		default:
			return m_pInputControl->GetKey(keyCode);
		}
	}
	bool InputControlItemSongSelect::GetKeyUp(int key)
	{
		return m_pInputControl->GetKeyUp(key);
	}
	bool InputControlItemSongSelect::GetKeyDown(int key)
	{
		return m_pInputControl->GetKeyDown(key);
	}
	InputControlItemSongSelect::InputControlItemSongSelect()
	{
		m_pInputControl = &Input::GetInstance();
	}
	InputControlItemSongSelect::~InputControlItemSongSelect()
	{
	}
}