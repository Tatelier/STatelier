#pragma once

namespace STatelier {
	class SceneControl;

	class Supervision {
	public:
		static void Initialize() {
			s_pInstance = new Supervision();
		}
		static Supervision* GetInstance() {
			return s_pInstance;
		}
		static void Finalize() {
			delete s_pInstance;
		}
		void Run();

		SceneControl* GetSceneControl();
	private:
		static Supervision* s_pInstance;

		SceneControl* m_pSceneControl;

		void Start();
		void Finish();
		void RefreshNowTime();
	};
}