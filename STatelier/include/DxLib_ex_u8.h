#pragma once

#include <DxLib.h>
#include <string>

struct CreateFontToHandleU8Info
{
	const std::u8string& u8FontName = u8"";
	int32_t Size = 32;
	int32_t Thick = 0;
	int32_t FontType = -1;
	int32_t CharSet = -1;
	int32_t EdgeSize = -1;
	int32_t Italic = FALSE;
	int32_t Handle = -1;
};

struct GetDrawStringSizeToHandleU8Info
{
	std::u8string u8str;
	int32_t StrLen;
	int32_t FontHandle;
	int32_t VerticalFlag = FALSE;
};

int32_t ChangeFont(const std::u8string& fontName);

int32_t CreateFontToHandle(const std::u8string& u8FontName, int32_t Size, int32_t Thick, int32_t FontType = -1, int32_t CharSet = -1, int32_t EdgeSize = -1, int32_t Italic = FALSE, int32_t Handle = -1);
int32_t CreateFontToHandle(const CreateFontToHandleU8Info& info);

int32_t GetDrawStringWidthToHandle(const char8_t* pStr, int32_t strLen, int32_t fontHandle, int32_t verticalFlag = FALSE);
int32_t GetDrawStringWidthToHandle(const std::u8string& u8str, int32_t fontHandle, int32_t verticalFlag = FALSE);

int32_t DrawStringFToHandle(float x, float y, const char8_t* pStr, uint32_t Color, int32_t FontHandle, uint32_t EdgeColor = 0, int32_t VerticalFlag = FALSE);
int32_t DrawStringFToHandle(float x, float y, const std::u8string& u8str, uint32_t Color, int32_t FontHandle, uint32_t EdgeColor = 0, int32_t VerticalFlag = FALSE);

int32_t GetDrawStringSizeToHandle(int32_t* SizeX, int32_t* SizeY, int32_t* LineCount, const char8_t* pStr, int32_t StrLen, int32_t FontHandle, int32_t VerticalFlag = FALSE);
int32_t GetDrawStringSizeToHandle(int32_t* SizeX, int32_t* SizeY, int32_t* LineCount, const std::u8string& u8str, int32_t StrLen, int32_t FontHandle, int32_t VerticalFlag = FALSE);
int32_t GetDrawStringSizeToHandle(int32_t* SizeX, int32_t* SizeY, int32_t* LineCount, const GetDrawStringSizeToHandleU8Info& info);