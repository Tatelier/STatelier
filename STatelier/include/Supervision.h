#pragma once

namespace STatelier {
	class SceneControl;
	class InputControl;
	class MessageBoxControl;


	class System
	{
	public:
		int GetDrawWidth()
		{
			return 1920;
		}
		int GetDrawHeight()
		{
			return 1080;
		}
	};
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

		System* GetSystem();
	private:
		static Supervision* s_pInstance;

		SceneControl* m_pSceneControl;
		InputControl* m_pInputControl;
		MessageBoxControl* pMessageBoxControl;
		System* pSystem;

		void Start();
		void Finish();
		void RefreshNowTime();
	};
}