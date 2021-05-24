#include <vector>

#include "DxLib.h"

#include "SceneControlMaster.h"
#include "Supervision.h"

#include "SongSelect/CategoryControl.h"

#include "ImageLoadControl.h"
#include "Input.h"

#include "Utility.h"

#include "MyMessageBox.h"

#pragma comment (lib, "gdiplus.lib")
#pragma comment (lib, "ole32.lib")


namespace Tatelier {

	Supervision& Supervision::GetInstance()
	{
		static Supervision instance;
		return instance;
	}

	int32_t Supervision::CommandSearchAndRun(const char* command, ...)
	{
		return 0;
	}

	void Supervision::Start()
	{
		Gdiplus::GdiplusStartup(&m_gdiplusToken, &m_pGdiplusStartupInput, 0);

		this->m_pSceneControl = &SceneControlMaster::GetInstance();
		this->m_pSceneControl->Start();
		std::vector<std::string> list;
		if (ttleGetFileNamesRecursive("Resources", &list, [](const std::string& a) {
			return ttleEndWithIndex(a, ".tja|.tlscore") > 0;
		})) {
		}

		ImageTextInfo info;
		info.Text = L"ダンガンノーツ";
		info.FontName = L"UD デジタル 教科書体 NK-B";
		info.EdgeSize = 6;
		info.FontSize = 64;
		info.Width = 800;
		info.Height = 130;
		int a = ImageLoadControl::GetInstance().CreateTextImageHandle(info);
		//MyMessageBox::GetInstance().Start();
		//auto messageInfo = new MyMessageBoxInfo();
		//auto messageItemInfo = MyMessageBoxItemInfo();
		//messageItemInfo.Callback = [this]() {
		//
		//};
		//messageItemInfo.Name = "Undefined2";
		//messageInfo->SetText("例外");
		//messageInfo->SsetMessageType(MyMessageType::Error);
		//messageInfo->Add(messageItemInfo);
		//messageInfo->Add(messageItemInfo);
		//MyMessageBox::GetInstance().Open(std::shared_ptr<MyMessageBoxInfo>(messageInfo));
	}

	void Supervision::Update()
	{
		m_nowMicroSecTime = GetNowHiPerformanceCount();
		m_nowMillisecTime = (int)(m_nowMicroSecTime / 1000);

		this->m_pSceneControl->Update();
		Input::GetInstance().Update();
		MyMessageBox::GetInstance().Update();
	}

	void Supervision::Draw()
	{
		this->m_pSceneControl->Draw();
		MyMessageBox::GetInstance().Draw();
	}

	void Supervision::Finish()
	{
		Gdiplus::GdiplusShutdown(m_gdiplusToken);
	}

	int64_t Supervision::GetNowMicroTime()
	{
		return m_nowMicroSecTime;
	}

	int32_t Supervision::GetNowMillisecTime()
	{
		return m_nowMillisecTime;
	}
}