#pragma once

#include <string>

namespace Tatelier {

	struct ImageTextInfo {
		std::wstring Text;
		std::wstring FontName;
		unsigned int Color = 0x000000;
		int FontSize = 16;
		int EdgeSize = 0;
		unsigned int EdgeColor = 0xFFFFFF;
		int Width = 100;
		int Height = 100;
	};

	class ImageLoadControl {
	public:
		static ImageLoadControl& GetInstance();
		int Load(const char* path);
		int Load(const std::string& path);
		int CreateTextImageHandle(const ImageTextInfo& info);
	};
}