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
		* @brief �e�L�X�g�摜���쐬���A���̉摜�n���h����Ԃ� ��detail�L
		* @param [in] info �e�L�X�g�摜�쐬���
		* @detail �����̉摜�œ������ō��ꂽ���̂�����΁A���̉摜�n���h����Ԃ��B
		*
		* @return �쐬�����摜�n���h��
		*/
		int CreateTextImageHandle(const ImageTextInfo& info);

		/**
		* @brief �摜���폜����
		* @param handle �摜�n���h��
		* @return 0: ����, 1:�܂��g���Ă���摜����, -1: �G���[
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