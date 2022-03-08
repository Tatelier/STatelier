#pragma once

namespace STatelier {
	class SceneControl;
	class InputControl;

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

		InputControl* GetInputControl();
	private:
		static Supervision* s_pInstance;

		SceneControl* m_pSceneControl;

		InputControl* m_pInputControl;

		void Start();
		void Finish();
		void RefreshNowTime();
	};
}