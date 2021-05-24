#pragma once

#include <stdint.h>
#include <windows.h>
#include <gdiplus.h>

namespace Tatelier {

	class SceneControlMaster;

	class Supervision {
	public:
		static Supervision& GetInstance();

		/**
		 * @brief �R�}���h����&���s
		 */
		int32_t CommandSearchAndRun(const char* command, ...);

		/**
		 * @brief ����������
		 */
		void Start();

		/**
		 * @brief �X�V����
		 * @detail ���t���[���Ăяo������
		 */
		void Update();

		/**
		 * @brief �`�揈��
		 * @detail ���t���[���Ăяo������
		 */
		void Draw();


		void Finish();

		/**
		 * @brief ���݂̃}�C�N���b
		 */
		int64_t GetNowMicroTime();
		/**
		 * @brief ���݂̃~���b
		 */
		int32_t GetNowMillisecTime();

	private:
		Supervision(const Supervision& a) { }
		Supervision() { }
		SceneControlMaster* m_pSceneControl;
		int64_t m_nowMicroSecTime;
		int32_t m_nowMillisecTime;
		ULONG_PTR m_gdiplusToken;
		Gdiplus::GdiplusStartupInput m_gdiplusStartupInput;
	};

}