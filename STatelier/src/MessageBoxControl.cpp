#include "MessageBoxControl.h"

#include <DxLib.h>
#include <Supervision.h>

#include <MessageBoxItem.h>

namespace
{
	const uint32_t DefaultColor = 0xf3f3f3;

	const uint32_t WarningColor = 0xBBBB00;
	const uint32_t WarningDarkColor = 0x888800;
	const uint32_t ErrorColor = 0xFF8888;
	const uint32_t ErrorLightColor = 0xFF8888;
	const uint32_t ErrorDarkColor = 0xBB4444;
	const uint32_t InfoColor = 0x3089CC;
	const uint32_t InfoDarkColor = 0x2570A2;

	int DrawCenterStringFToHandle(float cxf, float cyf, const std::string& text, unsigned int color, int fontHandle)
	{
		int sizeX = 0;
		int sizeY = 0;
		int lineCount = 0;
		
		GetDrawStringSizeToHandle(&sizeX, &sizeY, &lineCount, text.c_str(), text.size(), fontHandle, 0);

		float xf = cxf - sizeX / 2;
		float yf = cyf - sizeY / 2;
		return DrawStringFToHandle(xf, yf, text.c_str(), color, fontHandle);
	}

	class DrawBlendModeLock
	{
	public:
		DrawBlendModeLock()
		{
			GetDrawBlendMode(&mode, &param);
		}
		~DrawBlendModeLock()
		{
			SetDrawBlendMode(mode, param);
		}
	private:
		int mode;
		int param;
	};

	const int roundWidth = 20;

	int currentIndex = 0;
}

namespace STatelier
{
	void MessageBoxControl::Update()
	{
	}
	void MessageBoxControl::DrawButtonOther(const std::string& text, int x, int y, uint32_t clr)
	{
		int w = GetDrawStringWidthToHandle(text.c_str(), text.size(), component->GetDefaultFont());

		int l = x;
		int t = y;

		DrawStringToHandle(l + 37, t + 20, text.c_str(), clr, component->GetDefaultFont());
	}

	void MessageBoxControl::DrawButtonNowSelect(const std::string& text, int x, int y, uint32_t clr)
	{
		int w = GetDrawStringWidthToHandle(text.c_str(), text.size(), component->GetDefaultFont());

		int l = x;
		int t = y;

		uint32_t backColor = 0xFF0000;

		DrawRoundRectAA(
			l
			, t
			, l + w + 74
			, t + GetFontSizeToHandle(component->GetDefaultFont()) + 40
			, 30, 30
			, 10
			, backColor, FALSE, 3);

		DrawRoundRectAA(
			l
			, t
			, l + w + 74
			, t + GetFontSizeToHandle(component->GetDefaultFont()) + 40
			, 30, 30
			, 10
			, backColor, TRUE, 3);

		DrawStringToHandle(l + 37, t + 20, text.c_str(), clr, component->GetDefaultFont());
	}

	void MessageBoxControl::DrawAllButton(std::shared_ptr<MessageBoxItem> item, float right, float bottom)
	{
		uint32_t clr = 0xFFFFFF;

		switch (item->GetInfo().messageBoxType)
		{
			case MessageBoxType::Info:
				clr = InfoColor;
				break;
			case MessageBoxType::Warning:
				clr = WarningColor;
				break;
			case MessageBoxType::Error:
				clr = ErrorColor;
				break;
		}

		int l = right;
		int t = bottom + 40 + 20;

		for (int i = 0; i < item->GetInfo().messageBoxInfoExe.size(); i++)
		{
			auto& exeItem = item->GetInfo().messageBoxInfoExe[i];

			std::string text = exeItem.content;
			int w = GetDrawStringWidthToHandle(text.c_str(), text.size(), component->GetDefaultFont());

			l -= (w + 80);

			if (currentIndex == i)
			{
				DrawButtonNowSelect(text, l, t, 0x222e3f);
			}
			else
			{
				DrawButtonOther(text, l, t, clr);
			}
		}
	}
	void MessageBoxControl::Draw()
	{
		if (!enabled)
		{
			return;
		}

		DrawBox(0, 0, component->GetDrawWidth(), component->GetDrawHeight(), 0xFFFFFF, TRUE);

		// ‘S‘Ì‚ð•‚­‚·‚é
		{
			DrawBlendModeLock lock;

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 191);
			DrawBox(0, 0, component->GetDrawWidth(), component->GetDrawHeight(), 0, TRUE);
		}

		int width = 1280;
		int height = 840;

		// ˜g“h‚è‚Â‚Ô‚µ
		{
			DrawBlendModeLock lock;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 239);

			unsigned int BackgroundColor = 0x222e3f;

			DrawRoundRectAA(
				component->GetDrawWidthHalf() - width / 2
				, component->GetDrawHeightHalf() - height / 2
				, component->GetDrawWidthHalf() + width / 2
				, component->GetDrawHeightHalf() + height / 2
				, roundWidth, roundWidth
				, 10
				, BackgroundColor, TRUE);
		}

		const int innerFrameWidth = 15;
		unsigned int BackgroundInnerLineColor = 0x121e2f;

		// ˜g“à‚Ìü‚ð•`‰æ
		DrawRoundRectAA(
			component->GetDrawWidthHalf() - width / 2 + innerFrameWidth
			, component->GetDrawHeightHalf() - height / 2 + innerFrameWidth
			, component->GetDrawWidthHalf() + width / 2 - innerFrameWidth
			, component->GetDrawHeightHalf() + height / 2 - innerFrameWidth
			, roundWidth, roundWidth
			, 10
			, BackgroundInnerLineColor, FALSE, 5);

		std::shared_ptr<MessageBoxItem> item = itemList[0];

		// ƒwƒbƒ_[
		DrawCenterStringFToHandle(component->GetDrawWidthHalf(), component->GetDrawHeightHalf() - (height / 2) + 64, item->GetHeader(), item->GetTypeColor(), component->GetDefaultFont());
	
		// “à—e
		//DrawStringFToHandle(component->GetDrawWidthHalf(), component->GetDrawHeightHalf() - (height / 2) + 40, item->GetInfo().content.c_str(), DefaultColor, component->GetDefaultFont());

		int innerWidth = 1160;
		int innerHeight = 620;

		int left = component->GetDrawWidthHalf() - (innerWidth / 2);
		int top = component->GetDrawHeightHalf() - height / 2 + 120;
		int right = left + innerWidth;
		int bottom = top + innerHeight;
		// ƒ{ƒ^ƒ“
		DrawAllButton(item, right, bottom);
	}

	std::shared_ptr<MessageBoxItem> MessageBoxControl::Append(const MessageBoxInfo& info)
	{
		std::shared_ptr<MessageBoxItem> item = std::make_shared<MessageBoxItem>();
		item->Init(info);

		itemList.push_back(item);

		return item;
	}
}