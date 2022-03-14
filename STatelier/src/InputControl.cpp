#include "InputControl.h"

#include <DxLib.h>
#include <input.h>

namespace
{
}

namespace STatelier
{
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