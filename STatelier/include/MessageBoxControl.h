#pragma once

#include <memory>
#include <vector>
#include <string>

#include <MessageBoxInfo.h>
#include <DxLib.h>
#include <DxLib_ex_u8.h>

namespace STatelier
{
	class MessageBoxItem;

	class IMessageBoxControlComponent
	{
	public:
		int GetDrawWidth()
		{
			return 1920;
		}
		int GetDrawWidthHalf()
		{
			return 960;
		}
		int GetDrawHeight()
		{
			return 1080;
		}
		int GetDrawHeightHalf()
		{
			return 540;
		}
		int GetDefaultFont()
		{
			return fontHandle;
		}
		bool IsActiveMessageBox()
		{
			return true;
		}
		IMessageBoxControlComponent()
		{
			fontHandle = CreateFontToHandle(u8"UD ƒfƒWƒ^ƒ‹ ‹³‰È‘‘Ì NK-B", 40, 0, DX_FONTTYPE_ANTIALIASING_4X4);
		}
		~IMessageBoxControlComponent()
		{
			DeleteFontToHandle(fontHandle);
		}
	private:
		int fontHandle = -1;
	};

	class MessageBoxControl
	{
	public:
		void Init(IMessageBoxControlComponent* component)
		{
			this->component = component;
			Reset();
			this->fontHeaderHandle = CreateFontToHandle(GetFontName(), 40, 0, DX_FONTTYPE_ANTIALIASING_4X4);
			this->fontContentHandle = CreateFontToHandle(GetFontName(), 28, 0, DX_FONTTYPE_ANTIALIASING_4X4);
		}
		void Reset();
		void Update();
		void DrawHeader(std::shared_ptr<MessageBoxItem> item);
		void DrawButtonOther(float xf, float yf, const std::u8string& text, uint32_t textColor);
		void DrawButtonNowSelect(float xf, float yf, const std::u8string& text, uint32_t textColor, uint32_t backColor);
		void DrawAllButton(std::shared_ptr<MessageBoxItem> item, float right, float bottom);
		void Draw();
		std::shared_ptr<MessageBoxItem> Append(const MessageBoxInfo& info);
	private:
		bool enabled = false;
		int fontHeaderHandle = -1;
		int fontContentHandle = -1;
		IMessageBoxControlComponent* component;
		std::vector<std::shared_ptr<MessageBoxItem>> itemList;
	};
}