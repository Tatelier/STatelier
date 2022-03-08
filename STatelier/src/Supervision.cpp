#include "DxLib.h"
#include <experimental/generator>

#include <Supervision.h>
#include "SceneControl.h"

#include <InputControl.h>

#include "NoteType.h"

namespace STatelier 
{
	Supervision* Supervision::s_pInstance = nullptr;

	void Supervision::Run()
	{
		bool m_quit = false;

		SetOutApplicationLogValidFlag(FALSE);

		ChangeWindowMode(1);
		SetAlwaysRunFlag(1);

		SetWindowStyleMode(7);
		SetWindowSizeChangeEnableFlag(1);

		SetDoubleStartValidFlag(TRUE);

		DxLib_Init();
		SetUseGraphBaseDataBackup(FALSE);
		SetDrawScreen(DX_SCREEN_BACK);

		
		this->m_pSceneControl = new SceneControl();
		this->m_pInputControl = new InputControl();



		m_pSceneControl->Start();

		while (!m_quit) 
		{
			if (ProcessMessage() != 0) 
			{
				break;
			}
			ClearDrawScreen();

			m_pInputControl->Update();
			m_pSceneControl->Update();


			m_pSceneControl->Draw();

			ScreenFlip();
		}

#ifndef _DEBUG
		DxLib_End();
#endif
	}
	SceneControl* Supervision::GetSceneControl()
	{
		return m_pSceneControl;
	}

	InputControl* Supervision::GetInputControl()
	{
		return m_pInputControl;
	}
}