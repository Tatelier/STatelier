#pragma once

#include <cstdint>

#include "IInputControlItem.h"

namespace Tatelier {

	class Input;

	/**
	 * @brief ���̓R���g���[���A�C�e���N���X
	 */
	class InputControlItem : public IInputControlItem {
	public:
		/**
		 * @brief �L�[�̓��͐����擾����
		 *
		 * @param [in] key �L�[
		 * @return 0: ������, -1: ���ꂽ����, 1�ȏ�: ���͐�
		 */
		virtual int32_t GetCount(int key);

		/**
		 * @brief �L�[�����������ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ������, false: ������
		 */
		virtual bool GetKey(int key);

		/**
		 * @brief �L�[�𗣂������ォ�ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ����������, false: ����ł͂Ȃ�
		 */
		virtual bool GetKeyUp(int key);

		/**
		 * @brief �L�[�������������ォ�ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ������������, false: ����ł͂Ȃ�
		 */
		virtual bool GetKeyDown(int key);

		/**
		 * @brief �L�����ǂ������擾����
		 *
		 * @return true: �L��, false: ����
		 */
		bool IsEnabled();

		/**
		 * @brief �L�����ǂ�����ݒ肷��
		 * 
		 * @param [in] enabled true: �L��, false: ����
		 */
		void SetEnbaled(bool enable);

		/**
		 * @brief �R���X�g���N�^
		 */
		InputControlItem();

		/**
		 * @brief �f�X�g���N�^
		 */
		virtual ~InputControlItem();
	protected:
		Input* m_pInputControl;
	private:
		bool m_enabled;
	};
}