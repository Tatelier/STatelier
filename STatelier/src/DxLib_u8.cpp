#include <DxLib_u8.h>

int32_t ChangeFont(const char8_t* fontName)
{
    return ChangeFont((const TCHAR*)fontName);
}

int32_t CreateFontToHandle(const char8_t* FontName, int32_t Size, int32_t Thick, int32_t FontType, int32_t CharSet, int32_t EdgeSize, int32_t Italic, int32_t Handle)
{
    return CreateFontToHandle((const TCHAR*)FontName, Size, Thick, FontType, CharSet, EdgeSize, Italic, Handle);
}
int32_t CreateFontToHandle(const std::u8string& u8FontName, int32_t Size, int32_t Thick, int32_t FontType, int32_t CharSet, int32_t EdgeSize, int32_t Italic, int32_t Handle)
{
    return CreateFontToHandle(u8FontName.c_str(), Size, Thick, FontType, CharSet, EdgeSize, Italic, Handle);
}

int32_t CreateFontToHandle(const CreateFontToHandleU8Info& info)
{
    return CreateFontToHandle(info.u8FontName.c_str(), info.Size, info.Thick, info.FontType, info.CharSet, info.EdgeSize, info.Italic, info.Handle);
}

int32_t GetDrawStringWidthToHandle(const char8_t* pStr, int32_t strLen, int32_t fontHandle, int32_t verticalFlag)
{
    return GetDrawStringWidthToHandle((const TCHAR*)pStr, strLen, fontHandle, verticalFlag);
}
int32_t GetDrawStringWidthToHandle(const std::u8string& u8str, int32_t strLen, int32_t fontHandle, int32_t verticalFlag)
{
    return GetDrawStringWidthToHandle(u8str.c_str(), strLen, fontHandle, verticalFlag);
}
int32_t GetDrawStringWidthToHandle(const std::u8string& u8str, int32_t fontHandle, int32_t verticalFlag)
{
    return GetDrawStringWidthToHandle(u8str.c_str(), u8str.size(), fontHandle, verticalFlag);
}

int32_t GetDrawStringSizeToHandle(int32_t* SizeX, int32_t* SizeY, int32_t* LineCount, const char8_t* pStr, int32_t StrLen, int32_t FontHandle, int32_t VerticalFlag)
{
    return GetDrawStringSizeToHandle(SizeX, SizeY, LineCount, (const TCHAR*)pStr, StrLen, FontHandle, VerticalFlag);
}
int32_t GetDrawStringSizeToHandle(int32_t* SizeX, int32_t* SizeY, int32_t* LineCount, const std::u8string& u8str, int32_t StrLen, int32_t FontHandle, int32_t VerticalFlag)
{
    return GetDrawStringSizeToHandle(SizeX, SizeY, LineCount, u8str.c_str(), StrLen, FontHandle, VerticalFlag);
}

int32_t GetDrawStringSizeToHandle(int32_t* SizeX, int32_t* SizeY, int32_t* LineCount, const GetDrawStringSizeToHandleU8Info& info)
{
    return GetDrawStringSizeToHandle(SizeX, SizeY, LineCount, info.u8str, info.StrLen, info.FontHandle, info.VerticalFlag);
}

int32_t DrawStringFToHandle(float x, float y, const char8_t* pStr, uint32_t Color, int32_t FontHandle, uint32_t EdgeColor, int32_t VerticalFlag)
{
    return DrawStringFToHandle(x, y, (const TCHAR*)pStr, Color, FontHandle, EdgeColor, VerticalFlag);
}
int32_t DrawStringFToHandle(float x, float y, const std::u8string& u8str, uint32_t Color, int32_t FontHandle, uint32_t EdgeColor, int32_t VerticalFlag)
{
    return DrawStringFToHandle(x, y, u8str.c_str(), Color, FontHandle, EdgeColor, VerticalFlag);
}