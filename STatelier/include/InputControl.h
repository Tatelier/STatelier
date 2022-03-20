#pragma once

#include <vector>
#include <array>

#include <IInput.h>

namespace STatelier
{
	class MessageBoxControl;

	class IInputControl
	{
	public:
		
	};

	class InputControl : public IInputControl
	{
	public:
		const std::array<char, 256>& GetStateBuffer()
		{
			return buffer;
		}
		void Update();

		void SetMessageBoxControl(MessageBoxControl* pMessageBoxControl)
		{
			this->pMessageBoxControl = pMessageBoxControl;
		}

		void RegistMessageBoxInput(IInput* pInput)
		{
			pMessageBoxInput = pInput;
		}

		void UnregistMessageBoxInput()
		{
			pMessageBoxInput = nullptr;
		}

		void Regist(IInput* input)
		{
			m_pInputList.push_back(input);
		}

		template<typename Iterator>
		void Unregist(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				auto position = std::find(m_pInputList.begin(), m_pInputList.end(), *begin);
				if (position != m_pInputList.end())
				{
					m_pInputList.erase(position);
				}
				begin++;
			}
		}
		~InputControl()
		{
			m_pInputList.clear();
		}
	private:
		MessageBoxControl* pMessageBoxControl;
		IInput* pMessageBoxInput;
		std::vector<IInput*> m_pInputList;
		std::array<char, 256> buffer = { 0 };
	};
}