#include "ImageLoadControl.h"
#include <windows.h>
#include <gdiplus.h>

#include <vector>

#include "DxLib.h"

#define PNG_CLSID L"{557cf406-1a04-11d3-9a73-0000f81ef32e}"


namespace Tatelier {

	ImageLoadControl& ImageLoadControl::GetInstance()
	{
		static ImageLoadControl instance;

		return instance;
	}

	int ImageLoadControl::Load(const char* path)
	{
		return LoadGraph(path);
	}

	int ImageLoadControl::Load(const std::string& path)
	{
		return Load(path.c_str());
	}

	int ImageLoadControl::LoadText(const ImageTextInfo& info)
	{
		int handle = -1;
		int status;

		Gdiplus::Bitmap bmp(info.Width, info.Height, PixelFormat32bppARGB);
		Gdiplus::Graphics gps(&bmp);

		gps.SetTextRenderingHint(Gdiplus::TextRenderingHint::TextRenderingHintAntiAlias);
		gps.SetInterpolationMode(Gdiplus::InterpolationMode::InterpolationModeBilinear);
		gps.SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeAntiAlias);

		Gdiplus::Font ff(info.FontName.c_str(), info.FontSize);
		Gdiplus::GraphicsPath gp;
		const Gdiplus::StringFormat* sf = Gdiplus::StringFormat::GenericTypographic();
		// 
		//gp.AddString(text, ff.FontFamily, (int)ff.Style,
		//	ff.SizeInPoints, Point.Empty, sf);
		{
			Gdiplus::FontFamily ffamily;
			status = ff.GetFamily(&ffamily);
			gp.AddString(info.Text.c_str(), info.Text.size(), &ffamily, ff.GetStyle(),
				ff.GetSize(), Gdiplus::Point(), sf);
		}


		Gdiplus::Rect a;
		status = gp.GetBounds(&a);
		if (status != 0) {
			// TODO: ERROR
		}

		float penSize = 1.0f;

		if (a.Width > 0 && a.Height > 0) {
			Gdiplus::Bitmap bmp2(a.Width + info.EdgeSize, a.Height + info.EdgeSize);
			Gdiplus::Graphics gps2(&bmp2);

			gps2.SetTextRenderingHint(Gdiplus::TextRenderingHint::TextRenderingHintAntiAlias);
			gps2.SetCompositingQuality(Gdiplus::CompositingQuality::CompositingQualityHighQuality);
			gps2.SetCompositingMode(Gdiplus::CompositingMode::CompositingModeSourceOver);
			gps2.SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeAntiAlias);
			gps2.TranslateTransform(-(a.X + penSize) + info.EdgeSize / 2, -(a.Y + penSize) + info.EdgeSize / 2);

			if (info.EdgeSize > 0)
			{
				Gdiplus::Pen drawPen(Gdiplus::Color((Gdiplus::ARGB)(info.EdgeColor | 0xFF000000)), info.EdgeSize);
				drawPen.SetLineJoin(Gdiplus::LineJoin::LineJoinRound);

				Gdiplus::Pen drawPenHalf(Gdiplus::Color((Gdiplus::ARGB)(info.EdgeColor | 0xFF000000)), info.EdgeSize / 2.0F);
				drawPenHalf.SetLineJoin(Gdiplus::LineJoin::LineJoinRound);

				gps2.DrawPath(&drawPen, &gp);
				gps2.DrawPath(&drawPenHalf, &gp);
			}

			Gdiplus::SolidBrush fillBrush((Gdiplus::ARGB)(info.Color | 0xFF000000));
			gps2.FillPath(&fillBrush, &gp);

			switch (1)
			{
			case 1:
				gps.DrawImage(&bmp2, (INT)(info.Width / 2 - bmp2.GetWidth() / 2), (INT)(info.Height / 2 - bmp2.GetHeight() / 2));
				break;
			case 0:
				//gps.DrawImage(bmp2, 0, 0);
				break;
			}
		}


		CLSID clsid;
		CLSIDFromString(PNG_CLSID, &clsid);

		int hresult;
		IStream* pIStream;
		hresult = ::CreateStreamOnHGlobal(NULL, TRUE, &pIStream);

		Gdiplus::Status sstatus = bmp.Save(pIStream, &clsid);

		HGLOBAL hg = NULL;
		GetHGlobalFromStream(pIStream, &hg);
		int bufSize = GlobalSize(hg);

		LPVOID pImage = GlobalLock(hg);
		std::vector<uint8_t> data;
		data.resize(bufSize);
		memcpy(&data[0], pImage, bufSize);
		GlobalUnlock(hg);

		SetDrawValidGraphCreateFlag(TRUE);
		SetDrawValidAlphaChannelGraphCreateFlag(TRUE);

		handle = CreateGraphFromMem(&data[0], bufSize);

		SetDrawValidGraphCreateFlag(FALSE);
		SetDrawValidAlphaChannelGraphCreateFlag(FALSE);

		pIStream->Release();
		return handle;
	}
}