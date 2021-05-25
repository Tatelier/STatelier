#pragma once

#include <cstdint>

namespace Tatelier {
	/**
	 * @brief ���̓A�C�e���C���^�[�t�F�[�X
	 */
	class IInputControlItem {
	public:
		/**
		 * @brief �L�����ǂ������擾����
		 * @return true: �L��, false: ����
		 */
		virtual bool IsEnabled() = 0;

		/**
		 * @brief �L�����ǂ�����ݒ肷��
		 * 
		 * @param [in] enabled true: �L��, false: ����
		 */
		virtual void SetEnabled(bool enabled) = 0;

        /**
		 * @brief �L�[�̓��͐����擾����
		 *
		 * @param [in] key �L�[
		 * @return 0: ������, -1: ���ꂽ����, 1�ȏ�: ���͐�
		 */
        virtual int32_t GetCount(int key) = 0;

        /**
		 * @brief �L�[�����������ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ������, false: ������
		 */
		virtual bool GetKey(int key) = 0;

        /**
		 * @brief �L�[�𗣂������ォ�ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ����������, false: ����ł͂Ȃ�
		 */
		virtual bool GetKeyUp(int key) = 0;

        /**
		 * @brief �L�[�������������ォ�ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ������������, false: ����ł͂Ȃ�
		 */
		virtual bool GetKeyDown(int key) = 0;
	};
}