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
			// ���b�Z�[�W�{�b�N�X���\������Ă���ꍇ�́A
			// �W����Input���X�V���Ȃ�
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