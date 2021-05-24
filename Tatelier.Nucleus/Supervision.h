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
		 * @brief コマンド検索&実行
		 */
		int32_t CommandSearchAndRun(const char* command, ...);

		/**
		 * @brief 初期化処理
		 */
		void Start();

		/**
		 * @brief 更新処理
		 * @detail 毎フレーム呼び出すこと
		 */
		void Update();

		/**
		 * @brief 描画処理
		 * @detail 毎フレーム呼び出すこと
		 */
		void Draw();


		void Finish();

		/**
		 * @brief 現在のマイクロ秒
		 */
		int64_t GetNowMicroTime();
		/**
		 * @brief 現在のミリ秒
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