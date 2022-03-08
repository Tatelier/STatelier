#pragma once

#include <IInput.h>

namespace STatelier
{
	class InputControl;

	class Input : public IInput
	{
	public:
		int GetCount(int keyCode);
		void Update();
		Input(InputControl* pInputControl);
	private:
		InputControl* m_pInputControl;
		int bytes[256] = { 0 };
		bool m_enabled = true;
	};
}