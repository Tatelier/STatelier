#include "DxLib.h"
#include <DxLib_ex_u8.h>
#include <experimental/generator>

#include <Supervision.h>

#include <SceneControl.h>
#include <InputControl.h>
#include <MessageBoxControl.h>

#include <Graphics/Utility.h>

#include "NoteType.h"

namespace STatelier 
{
	Supervision* Supervision::s_pInstance = nullptr;

	

	void Supervision::Run()
	{
		bool m_quit = false;

		STatelier::Graphics::GraphicsInit();

		SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);

		SetOutApplicationLogValidFlag(FALSE);

		ChangeWindowMode(1);
		SetAlwaysRunFlag(1);

		SetWindowStyleMode(7);
		SetWindowSizeChangeEnableFlag(1);

		SetDoubleStartValidFlag(TRUE);

		ChangeFont(u8"UD デジタル 教科書体 NK-B");
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
		this->pSystem = new System();

		this->pMessageBoxControl->Init(&imbcc);


		this->m_pInputControl->SetMessageBoxControl(this->pMessageBoxControl);

		m_pSceneControl->Start();
		//MessageBoxInfo info;
		//info.messageBoxType = MessageBoxType::Error;
		//info.content = u8"";
		//pMessageBoxControl->Append(info);

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

			//DrawGraph(0, 0, handle, TRUE);

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