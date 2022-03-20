#include <Graphics/Utility.h>
#include <windows.h>
#include <gdiplus.h>
#include <string>
#include <DxLib.h>
#include <Shlwapi.h>
#include <ObjIdl.h>
#include <iostream>
#include <fstream>

#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "gdiplus.lib")

namespace
{
	ULONG_PTR lpToken;
	Gdiplus::GdiplusStartupInput gpSI;
	int gdiInitCount = 0;
}

namespace STatelier::Graphics
{
	int GraphicsInit()
	{
		if (gdiInitCount == 0)
		{
			Gdiplus::GdiplusStartup(&lpToken, &gpSI, NULL);
		}
		gdiInitCount++;

		return 0;
	}
	int GraphicsFin()
	{
		gdiInitCount--;

		if (gdiInitCount == 0)
		{
			Gdiplus::GdiplusShutdown(lpToken);
		}

		return 0;
	}
	bool TryA(const std::u8string& source, std::wstring* dest)
	{
		int size = MultiByteToWideChar(
			CP_UTF8
			, 0
			, (LPCCH)source.c_str()
			, -1
			, NULL
			, 0);

		WCHAR* d = new WCHAR[size];

		MultiByteToWideChar(
			CP_UTF8
			, 0
			, (LPCCH)source.c_str()
			, -1
			, d
			, size);

		// wstringインスタンスにコピー
		*dest = d;

		// コピーできたのでdelete
		delete d;

		return true;
	}

	int CreateTextImageHandle(const CreateTextImageHandleInfo& info)
	{
		int result = -1;

		std::wstring wFontName;
		std::wstring wText;

		// WCHARへの変換
		TryA(info.u8FontName, &wFontName);
		TryA(info.u8Text, &wText);

		Gdiplus::Bitmap bmp(info.width, info.height);
		Gdiplus::Graphics* gps = Gdiplus::Graphics::FromImage(&bmp);

		gps->SetTextRenderingHint(Gdiplus::TextRenderingHint::TextRenderingHintAntiAlias);
		gps->SetInterpolationMode(Gdiplus::InterpolationMode::InterpolationModeBilinear);
		gps->SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeAntiAlias);

		Gdiplus::Font font(wFontName.c_str(), info.fontSize);
		Gdiplus::FontFamily ff;
		const Gdiplus::StringFormat* sf;

		Gdiplus::GraphicsPath gp;

		font.GetFamily(&ff);
		sf = Gdiplus::StringFormat::GenericTypographic();

		gp.AddString(wText.c_str(), wText.size(), &ff, font.GetStyle(), font.GetSize(), Gdiplus::PointF(), sf);

		Gdiplus::Rect bounds;
		gp.GetBounds(&bounds);

		float penSize = 1.0F;

		if (bounds.Width > 0 && bounds.Height > 0)
		{
			Gdiplus::Bitmap bmp2((int)bounds.Width + info.edgeSize, (int)bounds.Height + info.edgeSize);
			Gdiplus::Graphics* gps2 = Gdiplus::Graphics::FromImage(&bmp2);
			{
				gps2->SetTextRenderingHint(Gdiplus::TextRenderingHint::TextRenderingHintAntiAlias);
				gps2->SetCompositingQuality(Gdiplus::CompositingQuality::CompositingQualityHighQuality);
				gps2->SetCompositingMode(Gdiplus::CompositingMode::CompositingModeSourceOver);


				gps2->SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeAntiAlias);
				gps2->TranslateTransform(-(bounds.X + penSize) + info.edgeSize / 2, -(bounds.Y + penSize) + info.edgeSize / 2);

				if (info.edgeSize > 0)
				{
					Gdiplus::Pen drawPen(Gdiplus::ARGB(0xFF000000) | Gdiplus::ARGB(info.edgeColor), info.edgeSize);
					drawPen.SetLineJoin(Gdiplus::LineJoin::LineJoinRound);

					Gdiplus::Pen drawPenHalf(Gdiplus::ARGB(0xFF000000) | Gdiplus::ARGB(info.edgeColor), info.edgeSize / 2.0F);
					drawPenHalf.SetLineJoin(Gdiplus::LineJoin::LineJoinRound);

					gps2->DrawPath(&drawPen, &gp);
					gps2->DrawPath(&drawPenHalf, &gp);
				}

				Gdiplus::SolidBrush fillBrush(Gdiplus::ARGB(0xFF000000) | Gdiplus::ARGB(info.color));
				gps2->FillPath(&fillBrush, &gp);


				gps->DrawImage(&bmp2, (INT)(bmp.GetWidth() / 2 - bmp2.GetWidth() / 2), (INT)(bmp.GetHeight() / 2 - bmp2.GetHeight() / 2));


				//write to IStream
				IStream* istream = nullptr;

				HRESULT hr = CreateStreamOnHGlobal(NULL, TRUE, &istream);
				CLSID clsid;
				CLSIDFromString(L"{557CF406-1A04-11D3-9A73-0000F81EF32E}", &clsid);

				Gdiplus::Status status;

				status = bmp.Save(istream, &clsid);

				ULARGE_INTEGER liSize;
				IStream_Size(istream, &liSize);

				void* bytes = malloc(liSize.QuadPart);

				LARGE_INTEGER a = { 0 };
				ULARGE_INTEGER b;

				istream->Seek(a, STREAM_SEEK_SET, &b);
				HRESULT ret = istream->Read(bytes, liSize.QuadPart, NULL);

				SetDrawValidGraphCreateFlag(TRUE);
				SetDrawValidAlphaChannelGraphCreateFlag(TRUE);

				result = CreateGraphFromMem(bytes, liSize.QuadPart);

				SetDrawValidGraphCreateFlag(FALSE);
				SetDrawValidAlphaChannelGraphCreateFlag(FALSE);

				free(bytes);
				istream->Release();
			}
			delete gps2;
		}
		delete gps;

		return result;
	}
}