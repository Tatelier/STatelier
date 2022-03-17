#include "DxLib.h"
#include <DxLib_u8.h>
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

		SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);

		SetOutApplicationLogValidFlag(FALSE);

		ChangeWindowMode(1);
		SetAlwaysRunFlag(1);

		SetWindowStyleMode(7);
		SetWindowSizeChangeEnableFlag(1);

		SetDoubleStartValidFlag(TRUE);

		ChangeFont(u8"UD ƒfƒWƒ^ƒ‹ ‹³‰È‘‘Ì NK-B");
		SetFontSize(48);
		ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
		
		SetGraphMode(1920, 1080, 32);
		SetWindowSize(240, 135);

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
		info.content = u8"";
		pMessageBoxControl->Append(info);

		while (!m_quit) 
		{
			if (ProcessMessage() != 0) 
			{
				break;
			}
			ClearDrawScreen();

			m_pInputControl->Update();
			pMessageBoxControl->Update();
			m_pSceneControl->Update();

			m_pSceneControl->Draw();

			pMessageBoxControl->Draw();

			ScreenFlip();
		}

#ifndef STATELIER_DEBUG
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