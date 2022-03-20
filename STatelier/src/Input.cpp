#include "Input.h"

#include <InputControl.h>

#include <DxLib.h>


namespace STatelier
{
	int Input::GetCount(int keyCode) const
	{
		return bytes[keyCode];
	}

	bool Input::GetKey(int keyCode) const
	{
		return bytes[keyCode] > 0;
	}

	bool Input::GetKeyDown(int keyCode) const
	{
		return bytes[keyCode] == 1;
	}

	bool Input::GetKeyUp(int keyCode) const
	{
		return bytes[keyCode] == -1;
	}

	void Input::Reset()
	{
		for (size_t i = 0; i < 256; i++)
		{
			bytes[i] = 0;
		}
	}

	void Input::Update()
	{
		if (!m_enabled)
		{
			Reset();
			return;
		}

		auto& buffer = m_pInputControl->GetStateBuffer();

		for (size_t i = 0; i < buffer.size(); i++)
		{
			if (buffer[i] > 0)
			{
				bytes[i] = bytes[i] == -1 ? 1 : (bytes[i] + 1);
			}
			else
			{
				bytes[i] = bytes[i] > 0 ? -1 : 0;
			}
		}
	}
	bool Input::IsEnabled() const
	{
		return m_enabled;
	}
	void Input::SetEnabled(bool enabled)
	{
		m_enabled = enabled;
	}
	Input::Input(InputControl* pInputControl)
	{
		m_pInputControl = pInputControl;
	}
}