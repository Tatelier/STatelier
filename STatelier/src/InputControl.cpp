#include "InputControl.h"

#include <DxLib.h>
#include <input.h>

namespace
{
}

namespace STatelier
{
	IInput* InputControl::CreateInput()
	{
		IInput* input = new Input(this);
		m_pInputList.push_back(input);

		return input;
	}

	void InputControl::Update()
	{
		if (GetHitKeyStateAll(buffer.data()) == 0)
		{

		}

		for (size_t i = 0; i < m_pInputList.size(); i++)
		{
			m_pInputList[i]->Update();
		}
	}
}