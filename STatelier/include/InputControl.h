#pragma once

#include <vector>
#include <array>

#include <IInput.h>

namespace STatelier
{
	class IInputControl
	{
	public:

	};

	class InputControl : public IInputControl
	{
	public:
		template <class T>
		IInput* Create()
		{
			IInput* input = new T();
			m_pInputList.push_back(input);
		}
		IInput* CreateInput();
		const std::array<char, 256>& GetStateBuffer()
		{
			return buffer;
		}
		void Update();
		~InputControl()
		{
			for (size_t i = 0; i < m_pInputList.size(); i++)
			{
				delete m_pInputList[i];
			}
		}
	private:
		std::vector<IInput*> m_pInputList;
		std::array<char, 256> buffer = { 0 };
	};
}