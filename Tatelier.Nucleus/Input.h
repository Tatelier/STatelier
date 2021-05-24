#pragma once
#include <cstdint>

#include "DxLib.h"

namespace Tatelier {

	/**
	 * @brief �L�[���̓N���X ���V���O���g��
	 */
	class Input {
	public:
		/**
		 * @brief �V���O���g���C���X�^���X���擾����
		 * 
		 * @return �C���X�^���X
		 */
		static Input& GetInstance();

		/**
		 * @brief �L�[�̓��͐����擾����
		 *
		 * @param [in] key �L�[
		 * @return 0: ������, -1: ���ꂽ����, 1�ȏ�: ���͐�
		 */
		int32_t GetCount(int key);

		/**
		 * @brief �L�[�����������ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ������, false: ������
		 */
		bool GetKey(int key);

		/**
		 * @brief �L�[�𗣂������ォ�ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ����������, false: ����ł͂Ȃ�
		 */
		bool GetKeyUp(int key);

		/**
		 * @brief �L�[�������������ォ�ǂ������擾����
		 *
		 * @param [in] key �L�[
		 * @return true: ������������, false: ����ł͂Ȃ�
		 */
		bool GetKeyDown(int key);

		/**
		 * @brief �X�V����
		 *
		 * @remark ���C�����[�v�ŃR�[�����邱��
		 */
		void Update();
	private:
		const static int32_t BytesLen = 256;

		char bytes[BytesLen];
		int32_t cntBytes[BytesLen];

		Input() { }
		Input(const Input& instance) { }
	};
}