#include "Tatelier_API.h"

#include <memory>

#include "DxLib.h"
#include "Supervision.h"

#include "ThemeConfig.h"

#include "Error.h"
#include <stdexcept>


using namespace Tatelier;

DllExport void Start()
{
	// TODO: ����������
}


DllExport void Run()
{

	try {

		auto& supervision = Supervision::GetInstance();

		const char* title = "Tatelier 2020.05.16.0";

		ThemeConfig::Start();

		SetOutApplicationLogValidFlag(FALSE);

		SetMainWindowText(title);
		SetGraphMode(ThemeConfig::GetInstance().GetDrawMode().Width, ThemeConfig::GetInstance().GetDrawMode().Height, 32);
		SetWindowSize(ThemeConfig::GetInstance().GetWindow().Width, ThemeConfig::GetInstance().GetWindow().Height);
		ChangeWindowMode(1);
		SetAlwaysRunFlag(1);
		// �c�w���C�u������ WM_PAINT ���b�Z�[�W�̏������s��Ȃ��悤�ɂ���
		//SetUseDxLibWM_PAINTProcess(0);
		SetWindowStyleMode(7);
		SetWindowSizeChangeEnableFlag(1);
		//ChangeFont("");
		ChangeFont("UD �f�W�^�� ���ȏ��� NK-B");
		ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
		SetFontSize(48);

		//SetBackgroundColor(0x26, 0x26, 0x26);
		//SetWindowVisibleFlag(FALSE);
		// ScreenFlip �����s���Ă����������M����҂��Ȃ�
		//SetWaitVSyncFlag(FALSE);
		SetMultiThreadFlag(TRUE);

		int prevX, prevY;

		if (DxLib_Init() != 0) {
			MessageBox(NULL, TEXT("DX���C�u�����̏������Ɏ��s���܂����B"),
				TEXT("���b�Z�[�W�{�b�N�X"), MB_OK);
			return;
		}

		SetDrawScreen(DX_SCREEN_BACK);

		supervision.Start();

		while (ProcessMessage() == 0) {
			ClearDrawScreen();
			supervision.Update();
			supervision.Draw();
			ScreenFlip();
		}
	}
	catch (...) {
	}
}

DllExport void Finish()
{
	DxLib_End();
}
