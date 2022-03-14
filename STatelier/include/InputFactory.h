#pragma once

#include <Input.h>
#include <InputControl.h>

#include <vector>

namespace STatelier
{
	class InputFactory
	{
	public:
		IInput* Create()
		{
			auto* input = new Input(m_pInputControl);
			m_inputList.push_back(input);

			m_pInputControl->Regist(input);

			return input;
		}
		void Init(InputControl* pInputControl)
		{
			Reset();
			m_pInputControl = pInputControl;
		}
		~InputFactory()
		{
			Reset();
		}
	private:
		void Reset()
		{
			m_pInputControl->Unregist(m_inputList.begin(), m_inputList.end());
			for (size_t i = 0; i < m_inputList.size(); i++)
			{
				delete m_inputList[i];
			}
			m_pInputControl = nullptr;
		}
		InputControl* m_pInputControl = nullptr;
		std::vector<IInput*> m_inputList;
	};
}