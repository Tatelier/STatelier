#pragma once

#include <IInput.h>
#include <IInputControl.h>

#include <vector>

namespace STatelier
{
	class InputFactory
	{
	public:
		IInput* Create()
		{
			auto* input = new T();
			m_inputList.push_back
		}
		InputFactory(IInputControl* pInputControl)
		{
			m_pInputControl = pInputControl;
		}
	private:
		IInputControl* m_pInputControl;
		std::vector<IInput*> m_inputList;
	};
}