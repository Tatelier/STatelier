#include "Input.h"

#include <InputControl.h>

#include <DxLib.h>


namespace STatelier
{
	int Input::GetCount(int keyCode) const
	{
		return bytes[keyCode];
	}

	void Input::Update()
	{
		if (!m_enabled)
		{
			for (size_t i = 0; i < 256; i++)
			{
				bytes[i] = 0;
			}
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