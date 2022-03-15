#include "MessageBoxControl.h"

#include <DxLib.h>
#include <DxLib_u8.h>
#include <Supervision.h>

#include <MessageBoxItem.h>

namespace
{
	const uint32_t DefaultColor = 0xf3f3f3;

	const uint32_t BackgroundColor = 0x222e3f;

	const uint32_t WarningColor = 0xBBBB00;
	const uint32_t WarningDarkColor = 0x888800;
	const uint32_t ErrorColor = 0xFF8888;
	const uint32_t ErrorLightColor = 0xFF8888;
	const uint32_t ErrorDarkColor = 0xBB4444;
	const uint32_t InfoColor = 0x3089CC;
	const uint32_t InfoDarkColor = 0x2570A2;

	const int32_t width = 1280;
	const int32_t height = 840;

	const int32_t innerWidth = 1160;
	const int32_t innerHeight = 620;

	const int32_t innerFrameWidth = 15;
	const int32_t innerFrameLineWeight = 5;

	const uint32_t BackgroundInnerLineColor = 0x121e2f;

	const int32_t roundWidth = 20;

	const int32_t posNum = 10;
	const int32_t buttonRoundWidth = 30;

	int currentIndex = 0;

	int DrawCenterStringFToHandle(float cxf, float cyf, const std::u8string& text, unsigned int color, int fontHandle)
	{
		int sizeX = 0;
		int sizeY = 0;
		int lineCount = 0;
		
		GetDrawStringSizeToHandle(&sizeX, &sizeY, &lineCount, text, text.size(), fontHandle, 0);

		float xf = cxf - sizeX / 2;
		float yf = cyf - sizeY / 2;

		return DrawStringFToHandle(xf, yf, text, color, fontHandle);
	}
	

	int GetCharU8(const char8_t* text, int size, int startIndex, std::array<char8_t, 7>* resultChar)
	{
		if (startIndex >= size)
		{
			return -1;
		}

		char8_t initial = text[startIndex];

		int resultSize = 1;

		if ((initial & 0xF0) == 0xF0)
		{
			resultSize = 4;
		}
		else if ((initial & 0xE0) == 0xE0)
		{
			resultSize = 3;
		}
		else if ((initial & 0xC0) == 0xC0)
		{
			resultSize = 2;
		}
		else if ((initial & 0x80) == 0x80)
		{
			return -2;
		}
		else
		{
			resultSize = 1;
		}

		int k = 0;
		for (int i = startIndex; i < startIndex + resultSize; i++)
		{
			resultChar->data()[k] = text[i];
			k++;
		}
		resultChar->data()[k] = '\0';

		return resultSize;
	}

	/**
	 * @brief UTF8Œ^‚Ì•¶Žš‚ð1•¶ŽšŽæ“¾‚·‚é
	 * @param text Žæ“¾Œ³•¶Žš—ñ
	 * @param startIndex Žæ“¾ŠJŽnˆÊ’u
	 * @param resultChar Žæ“¾‚µ‚½1•¶Žš
	 * @return Žæ“¾‚µ‚½1•¶Žš‚ÌƒTƒCƒY
	*/
	int GetCharU8(const std::u8string& text, int startIndex, std::array<char8_t, 7>* resultChar)
	{
		return GetCharU8(text.c_str(), text.size(), startIndex, resultChar);
	}
	int DrawObtainsString2F(float x, float y, float AddY, const RECT& DrawArea, const char8_t* text, uint32_t StrClr, int32_t fontHandle)
	{
		int StrLen;
		int i;
		float DrawX;
		float DrawY;
		int CharLen;
		float DrawWidth;

		DrawX = x;
		DrawY = y;

		std::array<char8_t, 7> t;

		int size = strlen((const TCHAR*)text) + 1;

		for (int i = 0; i < size;)
		{
			int charSize = GetCharU8(text, size, i, &t);
			if (charSize > 0)
			{
				// ‚P•¶Žš‚Ì•`‰æ•‚ðŽæ“¾
				DrawWidth = GetDrawStringWidthToHandle(t.data(), charSize, fontHandle);
				if (charSize == 1
					&& t.data()[0] == '\n')
				{
					DrawX = x;
					DrawY += AddY;
				}
				else 
				if (DrawX + DrawWidth > DrawArea.right)
				{
					DrawX = x;
					DrawY += AddY;
				}

				// ‚P•¶Žš•`‰æ
				DrawStringFToHandle(DrawX, DrawY, (const TCHAR*)t.data(), StrClr, fontHandle);

				// •`‰æÀ•W‚ð‚¸‚ç‚·
				DrawX += DrawWidth;

				i += charSize;

			}
			else
			{
				// error;
				break;
			}
		}

		return 0;
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

	uint32_t GetMasterColor(STatelier::MessageBoxType messageBoxType)
	{
		using namespace STatelier;

		uint32_t color = 0xFFFFFF;

		switch (messageBoxType)
		{
			case MessageBoxType::Info:
				color = InfoColor;
				break;
			case MessageBoxType::Warning:
				color = WarningColor;
				break;
			case MessageBoxType::Error:
				color = ErrorColor;
				break;
		}

		return color;
	}
}

namespace STatelier
{
	void MessageBoxControl::Reset()
	{
		if (this->fontHeaderHandle != -1)
		{
			DeleteFontToHandle(fontHeaderHandle);
			this->fontHeaderHandle = -1;
		}
		if (this->fontContentHandle != -1)
		{
			DeleteFontToHandle(fontContentHandle);
			this->fontContentHandle = -1;
		}
		std::u8string str = u8"a‚ ƒJ";



	}
	void MessageBoxControl::Update()
	{
		if (!enabled)
		{
			return;
		}


	}
	void MessageBoxControl::DrawButtonOther(float x, float y, const std::u8string& text, uint32_t textColor)
	{
		int w = GetDrawStringWidthToHandle(text, fontContentHandle);

		int l = x;
		int t = y;
		
		DrawStringFToHandle(l + 37, t + 20, text, textColor, fontContentHandle);
	}

	void MessageBoxControl::DrawButtonNowSelect(float x, float y, const std::u8string& text, uint32_t textColor, uint32_t backColor)
	{
		int w = GetDrawStringWidthToHandle(text, fontContentHandle);

		int l = x;
		int t = y;

		DrawRoundRectAA(
			l
			, t
			, l + w + 74
			, t + GetFontSizeToHandle(fontContentHandle) + 40
			, buttonRoundWidth, buttonRoundWidth
			, posNum
			, backColor, FALSE, 3);

		DrawRoundRectAA(
			l
			, t
			, l + w + 74
			, t + GetFontSizeToHandle(fontContentHandle) + 40
			, buttonRoundWidth, buttonRoundWidth
			, posNum
			, backColor, TRUE, 3);

		DrawStringFToHandle(l + 37, t + 20, text, textColor, fontContentHandle);
	}

	void MessageBoxControl::DrawAllButton(std::shared_ptr<MessageBoxItem> item, float right, float bottom)
	{
		uint32_t masterColor = GetMasterColor(item->GetInfo().messageBoxType);

		int l = right;
		int t = bottom - 20;

		for (int i = 0; i < item->GetInfo().messageBoxInfoExe.size(); i++)
		{
			auto& exeItem = item->GetInfo().messageBoxInfoExe[i];

			std::u8string text = exeItem.content;
			int w = GetDrawStringWidthToHandle(text.c_str(), text.size(), component->GetDefaultFont());

			l -= (w + 80);

			if (currentIndex == i)
			{
				DrawButtonNowSelect(l, t, text, BackgroundColor, masterColor);
			}
			else
			{
				DrawButtonOther(l, t, text, masterColor);
			}
		}
	}

	void MessageBoxControl::DrawHeader(std::shared_ptr<MessageBoxItem> item)
	{
		// ƒwƒbƒ_[
		DrawCenterStringFToHandle(
			component->GetDrawWidthHalf()
			, component->GetDrawHeightHalf() - (height / 2) + 64
			, item->GetHeader()
			, GetMasterColor(item->GetInfo().messageBoxType)
			, component->GetDefaultFont());
	}

	void MessageBoxControl::Draw()
	{
		if (!enabled)
		{
			return;
		}

		// ‘S‘Ì‚ð•‚­‚·‚é
		{
			DrawBlendModeLock lock;

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 191);
			DrawBox(0, 0, component->GetDrawWidth(), component->GetDrawHeight(), 0, TRUE);
		}


		// ˜g“h‚è‚Â‚Ô‚µ
		{
			DrawBlendModeLock lock;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 239);

			DrawRoundRectAA(
				component->GetDrawWidthHalf() - width / 2
				, component->GetDrawHeightHalf() - height / 2
				, component->GetDrawWidthHalf() + width / 2
				, component->GetDrawHeightHalf() + height / 2
				, roundWidth, roundWidth
				, posNum
				, BackgroundColor
				, TRUE);
		}


		// ˜g“à‚Ìü‚ð•`‰æ
		DrawRoundRectAA(
			component->GetDrawWidthHalf() - width / 2 + innerFrameWidth
			, component->GetDrawHeightHalf() - height / 2 + innerFrameWidth
			, component->GetDrawWidthHalf() + width / 2 - innerFrameWidth
			, component->GetDrawHeightHalf() + height / 2 - innerFrameWidth
			, roundWidth, roundWidth
			, posNum
			, BackgroundInnerLineColor
			, FALSE
			, innerFrameLineWeight);

		std::shared_ptr<MessageBoxItem> item = itemList[0];

		// ƒwƒbƒ_[
		DrawHeader(item);

		RECT rect{};
		rect.left = component->GetDrawWidthHalf() - (innerWidth / 2);
		rect.top = component->GetDrawHeightHalf() - height / 2 + 120;
		rect.right = rect.left + innerWidth;
		rect.bottom = rect.top + innerHeight;

		// “à—e
		DrawObtainsString2F(rect.left, rect.top, GetFontSizeToHandle(fontContentHandle) + 8, rect, item->GetInfo().content.c_str(), DefaultColor, fontContentHandle);

		// ƒ{ƒ^ƒ“
		DrawAllButton(item, rect.right, rect.bottom);
	}

	std::shared_ptr<MessageBoxItem> MessageBoxControl::Append(const MessageBoxInfo& info)
	{
		enabled = true;

		std::shared_ptr<MessageBoxItem> item = std::make_shared<MessageBoxItem>();
		item->Init(info);

		itemList.push_back(item);

		return item;
	}
}