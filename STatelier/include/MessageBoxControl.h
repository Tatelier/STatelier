#pragma once

#include <memory>
#include <vector>
#include <string>

#include <MessageBoxInfo.h>
#include <DxLib.h>

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
		IMessageBoxControlComponent()
		{
			fontHandle = CreateFontToHandle("UD ƒfƒWƒ^ƒ‹ ‹³‰È‘‘Ì NK-B", 40, 0, DX_FONTTYPE_ANTIALIASING_4X4);
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
		}
		void Update();
		void DrawButtonOther(const std::string& text, int x, int y, uint32_t clr);
		void DrawButtonNowSelect(const std::string& text, int x, int y, uint32_t clr);
		void DrawAllButton(std::shared_ptr<MessageBoxItem> item, float right, float bottom);
		void Draw();
		std::shared_ptr<MessageBoxItem> Append(const MessageBoxInfo& info);
	private:
		bool enabled = true;
		IMessageBoxControlComponent* component;
		std::vector<std::shared_ptr<MessageBoxItem>> itemList;
	};
}