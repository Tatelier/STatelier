#include "ImageCreateControl.h"

#include <windows.h>
#include <gdiplus.h>
#include <gdiplus.h>

#include <vector>

#include "DxLib.h"

#define PNG_CLSID L"{557cf406-1a04-11d3-9a73-0000f81ef32e}"

namespace Tatelier {
	ImageCreateControl* ImageCreateControl::CreateChildInstance()
	{
		auto item = new ImageCreateControl();
		m_ChildInstanceList.push_back(item);
		return item;
	}

	int ImageCreateControl::ReleaseChildInstance(ImageCreateControl* instance)
	{
		auto result = std::find_if(m_ChildInstanceList.begin(), m_ChildInstanceList.end(), [instance](ImageCreateControl* item) {
			return item == instance;
		});

		if (result != m_ChildInstanceList.end()) {
			m_ChildInstanceList.erase(result);
			delete *result;
		}
		else {
			return -1;
		}

		return 0;
	}
	int ImageCreateControl::CreateTextImageHandle(const ImageTextInfo& info)
	{
		int handle = -1;

		// �������̒T��
		auto result = std::find_if(m_ImageTextInfoManageItemList.begin(), m_ImageTextInfoManageItemList.end(), [info](ImageTextInfoManageItem& item) {
			return item.Info == info;
		});

		// �����̉摜������΂����Ԃ�
		if (result != m_ImageTextInfoManageItemList.end()) {
			result->UseCount++;
			return result->Handle;
		}

		Gdiplus::Bitmap bmp(info.Width, info.Height, PixelFormat32bppARGB);
		Gdiplus::Graphics gps(&bmp);

		gps.SetTextRenderingHint(Gdiplus::TextRenderingHint::TextRenderingHintAntiAlias);
		gps.SetInterpolationMode(Gdiplus::InterpolationMode::InterpolationModeBilinear);
		gps.SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeAntiAlias);

		Gdiplus::Font ff(info.FontName.c_str(), info.FontSize);
		Gdiplus::GraphicsPath gp;
		const Gdiplus::StringFormat* sf = Gdiplus::StringFormat::GenericTypographic();

		// TODO: C#�ł́Aff.SizeInPoints�����������AGDI+�ɂ͑��݂��Ȃ�
		// ���O�Ōv�Z����K�v�����肻���B
		//gp.AddString(text, ff.FontFamily, (int)ff.Style,
		//	ff.SizeInPoints, Point.Empty, sf);

		{
			Gdiplus::FontFamily ffamily;
			if (ff.GetFamily(&ffamily) != Gdiplus::Status::Ok) {
				// TODO: �G���[����
			}
			gp.AddString(info.Text.c_str(), info.Text.size(), &ffamily, ff.GetStyle(),
				ff.GetSize(), Gdiplus::Point(), sf);
		}

		Gdiplus::Rect rect;
		if (gp.GetBounds(&rect) != Gdiplus::Status::Ok) {
			// TODO: �G���[����
		}

		float penSize = 1.0f;

		if (rect.Width * rect.Height == 0) {
			// TODO: �G���[����
		}

		Gdiplus::Bitmap bmp2(rect.Width + info.EdgeSize, rect.Height + info.EdgeSize);
		Gdiplus::Graphics gps2(&bmp2);

		gps2.SetTextRenderingHint(Gdiplus::TextRenderingHint::TextRenderingHintAntiAlias);
		gps2.SetCompositingQuality(Gdiplus::CompositingQuality::CompositingQualityHighQuality);
		gps2.SetCompositingMode(Gdiplus::CompositingMode::CompositingModeSourceOver);
		gps2.SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeAntiAlias);
		gps2.TranslateTransform(-(rect.X + penSize) + info.EdgeSize / 2, -(rect.Y + penSize) + info.EdgeSize / 2);

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

		INT x, y;

		switch (info.Pivot)
		{
		case ImageTextInfo::Pivot::TopLeft:
		default: {
			x = y = 0;
		} break;
		case ImageTextInfo::Pivot::Center: {
			x = (INT)(info.Width / 2 - bmp2.GetWidth() / 2);
			y = (INT)(info.Height / 2 - bmp2.GetHeight() / 2);
		} break;
		}

		gps.DrawImage(&bmp2, x, y);

		CLSID clsid;

		if (::CLSIDFromString(PNG_CLSID, &clsid) != NOERROR) {
			// TODO: �G���[����
		}

		int hresult;
		IStream* pIStream;
		if (::CreateStreamOnHGlobal(NULL, TRUE, &pIStream) != NOERROR) {
			// TODO: �G���[����
		}

		Gdiplus::Status sstatus = bmp.Save(pIStream, &clsid);

		HGLOBAL hg;

		if (::GetHGlobalFromStream(pIStream, &hg) != NOERROR) {
			// TODO: �G���[����
		}

		int bufSize = ::GlobalSize(hg);

		LPVOID pImage = ::GlobalLock(hg);

		std::vector<uint8_t> data;
		data.resize(bufSize);

		if (memcpy_s(&data[0], bufSize, pImage, bufSize) != 0) {
			// TODO: �G���[����
		}

		if (::GlobalUnlock(hg) != 0) {
			// TODO: �G���[����
		}

		SetDrawValidGraphCreateFlag(TRUE);
		SetDrawValidAlphaChannelGraphCreateFlag(TRUE);

		handle = CreateGraphFromMem(&data[0], bufSize);

		SetDrawValidGraphCreateFlag(FALSE);
		SetDrawValidAlphaChannelGraphCreateFlag(FALSE);

		pIStream->Release();

		ImageTextInfoManageItem manageItem;
		manageItem.Handle = handle;
		manageItem.Info = info;
		manageItem.UseCount = 1;

		m_ImageTextInfoManageItemList.push_back(manageItem);

		return handle;
	}

	int ImageCreateControl::Delete(int handle)
	{
		//---- �ȉ��ACreateTextImageHandle�ɂ���č��ꂽ�摜�ŒT��

		// �������̒T��
		auto result = std::find_if(m_ImageTextInfoManageItemList.begin(), m_ImageTextInfoManageItemList.end(), [handle](ImageTextInfoManageItem& item) {
			return item.Handle == handle;
		});

		// �����̉摜���g�p�񐔂����炷
		if (result != m_ImageTextInfoManageItemList.end()) {
			result->UseCount--;
			if (result->UseCount == 0) {
				m_ImageTextInfoManageItemList.erase(result);
			}
		}
		else {
			// TODO: ���݂��Ȃ��摜
		}

		return 0;
	}

}