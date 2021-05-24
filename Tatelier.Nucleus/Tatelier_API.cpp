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
	// TODO: 初期化処理
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
		// ＤＸライブラリの WM_PAINT メッセージの処理を行わないようにする
		//SetUseDxLibWM_PAINTProcess(0);
		SetWindowStyleMode(7);
		SetWindowSizeChangeEnableFlag(1);
		//ChangeFont("");
		ChangeFont("UD デジタル 教科書体 NK-B");
		ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
		SetFontSize(48);

		//SetBackgroundColor(0x26, 0x26, 0x26);
		//SetWindowVisibleFlag(FALSE);
		// ScreenFlip を実行しても垂直同期信号を待たない
		//SetWaitVSyncFlag(FALSE);
		SetMultiThreadFlag(TRUE);

		int prevX, prevY;

		if (DxLib_Init() != 0) {
			MessageBox(NULL, TEXT("DXライブラリの初期化に失敗しました。"),
				TEXT("メッセージボックス"), MB_OK);
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
