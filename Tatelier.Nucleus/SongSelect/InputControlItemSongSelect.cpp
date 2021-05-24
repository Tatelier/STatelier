#include "InputControlItemSongSelect.h"
#include "../Input.h"

namespace Tatelier::SongSelect {
	bool InputControlItemSongSelect::GetKey(int keyCode)
	{
		if (!this->IsEnabled())
			return false;

		switch (keyCode) {
		case Prev:
			return GetKey(KEY_INPUT_L) || GetKey(KEY_INPUT_UP);
		default:
			return GetKey(keyCode);
		}
	}
	InputControlItemSongSelect::InputControlItemSongSelect()
	{
		input = &Input::GetInstance();
	}
}