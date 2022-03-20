#include "InputControl.h"

#include <DxLib.h>
#include <input.h>
#include <MessageBoxControl.h>

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

		if (pMessageBoxControl->IsActive())
		{
			// メッセージボックスが表示されている場合は、
			// 標準のInputを更新しない
			for (size_t i = 0; i < m_pInputList.size(); i++)
			{
				m_pInputList[i]->Reset();
			}
			pMessageBoxInput->Update();
		}
		else
		{
			pMessageBoxInput->Reset();
			for (size_t i = 0; i < m_pInputList.size(); i++)
			{
				m_pInputList[i]->Update();
			}
		}
	}
}