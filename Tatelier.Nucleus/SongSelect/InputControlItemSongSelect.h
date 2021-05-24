#pragma once

#include "../IInputControlItem.h"

namespace Tatelier {
	class Input;
}

namespace Tatelier::SongSelect {


	class InputControlItemSongSelect : public IInputControlItem {
	public:
		/**
		 * @brief 1�O�{�^��
		 */
		const static int Prev = -1;


		/**
		 * @brief �L�[�̓��͐����擾����
		 *
		 * @param [in] key �L�[
		 * @return 0: ������, -1: ���ꂽ����, 1�ȏ�: ���͐�
		 */
		int32_t GetCount(int key) override;

		/**
		 * @brief �L�[�����������ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ������, false: ������
		 */
		bool GetKey(int key) override;

		/**
		 * @brief �L�[�𗣂������ォ�ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ����������, false: ����ł͂Ȃ�
		 */
		bool GetKeyUp(int key) override;

		/**
		 * @brief �L�[�������������ォ�ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ������������, false: ����ł͂Ȃ�
		 */
		bool GetKeyDown(int key) override;
		InputControlItemSongSelect();
		~InputControlItemSongSelect();
	private:
		::Tatelier::Input* m_pInputControl;
	};

}
