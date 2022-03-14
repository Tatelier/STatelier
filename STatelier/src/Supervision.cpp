#include "DxLib.h"
#include <experimental/generator>

#include <Supervision.h>

#include <SceneControl.h>
#include <InputControl.h>
#include <MessageBoxControl.h>

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

		SetFontSize(48);
		
		SetGraphMode(1920, 1080, 32);
		SetWindowSize(480, 270);

		DxLib_Init();
		SetUseGraphBaseDataBackup(FALSE);
		SetDrawScreen(DX_SCREEN_BACK);


		IMessageBoxControlComponent imbcc;

		this->m_pSceneControl = new SceneControl();
		this->m_pInputControl = new InputControl();
		this->pMessageBoxControl = new MessageBoxControl();
		this->pMessageBoxControl->Init(&imbcc);

		this->pSystem = new System();

		m_pSceneControl->Start();
		MessageBoxInfo info;
		info.messageBoxType = MessageBoxType::Error;

		info.content = "��������͂��܂�";
		pMessageBoxControl->Append(info);

		while (!m_quit) 
		{
			if (ProcessMessage() != 0) 
			{
				break;
			}
			ClearDrawScreen();

			pMessageBoxControl->Update();
			m_pInputControl->Update();
			m_pSceneControl->Update();

			m_pSceneControl->Draw();

			pMessageBoxControl->Draw();

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
	System* Supervision::GetSystem()
	{
		return this->pSystem;
	}
}