#pragma once

#include <cstdint>
#include <string>

namespace STatelier::Graphics
{

	class CreateTextImageHandleInfo
	{
	public:
		void Init()
		{
		}
	public:
		int32_t fontSize;
		std::u8string u8FontName;
		std::u8string u8Text;
		int32_t edgeSize = 3;
		uint32_t edgeColor;
		uint32_t color;
		int32_t width;
		int32_t height;
	};

    int GraphicsInit();
    int CreateTextImageHandle(const CreateTextImageHandleInfo& info);
}