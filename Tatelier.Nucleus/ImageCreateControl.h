#pragma once

#include <cstdint>

#include <string>
#include <list>
#include <vector>

namespace Tatelier {
	struct ImageTextInfo {
		enum class Pivot {
			TopLeft = 0,
			Center,
		};
		std::wstring Text;
		std::wstring FontName;
		int32_t FontSize = 16;
		uint32_t Color = 0x000000;
		int32_t EdgeSize = 0;
		uint32_t EdgeColor = 0xFFFFFF;
		int32_t Width = 100;
		int32_t Height = 100;
		Pivot Pivot = Pivot::TopLeft;

		bool operator==(const ImageTextInfo& info2) {
			return Text == info2.Text
				&& FontName == info2.FontName
				&& FontSize == info2.FontSize
				&& Color == info2.Color
				&& EdgeColor == info2.EdgeColor
				&& Width == info2.Width
				&& Height == info2.Height
				&& Pivot == info2.Pivot
				;
		}
	};

	class ImageCreateControl
	{
	public:
		ImageCreateControl* CreateChildInstance();

		int ReleaseChildInstance(ImageCreateControl* instance);

		/**
		* @brief テキスト画像を作成し、その画像ハンドルを返す ※detail有
		* @param [in] info テキスト画像作成情報
		* @detail 既存の画像で同じ情報で作られたものがあれば、その画像ハンドルを返す。
		*
		* @return 作成した画像ハンドル
		*/
		int CreateTextImageHandle(const ImageTextInfo& info);

		/**
		* @brief 画像を削除する
		* @param handle 画像ハンドル
		* @return 0: 成功, 1:まだ使われている画像あり, -1: エラー
		*/
		int Delete(int handle);
	private:
		struct ImageTextInfoManageItem {
			ImageTextInfo Info;
			int Handle = -1;
			int UseCount = 0;
		};

		std::vector<ImageCreateControl*> m_ChildInstanceList;
		std::list<ImageTextInfoManageItem> m_ImageTextInfoManageItemList;
	};

}