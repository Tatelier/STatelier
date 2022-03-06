#include "DxLib.h"
#include <experimental/generator>

#include <Supervision.h>
#include "SceneControl.h"

#include "NoteType.h"

namespace STatelier {


	//class AAA
	//{
	//public:
	//	std::experimental::generator<int> GetStartEnumerator()
	//	{
	//		a = 3;
	//		co_yield 3;
	//		a = 1;
	//		co_yield 1;
	//		a = -1;
	//		co_yield -1;
	//	}
	//	AAA()
	//	{

	//	}
	//private:
	//	int a = 2;
	//};

	Supervision* Supervision::s_pInstance = nullptr;

	void Supervision::Run()
	{
		bool m_quit = false;

		SetOutApplicationLogValidFlag(FALSE);

		ChangeWindowMode(1);
		SetAlwaysRunFlag(1);

		SetWindowStyleMode(7);
		SetWindowSizeChangeEnableFlag(1);

		SetDoubleStartValidFlag(TRUE);

		DxLib_Init();
		SetUseGraphBaseDataBackup(FALSE);

		SceneControl* sceneControl = new SceneControl();
		sceneControl->Start();
		//auto aaa = new AAA();

		//auto ex = aaa->GetStartEnumerator();

		//for (auto const& state : aaa->GetStartEnumerator()) {

		//}
		//while (true)
		//{
		//	auto aa = ex.begin();
		//	if (aa == ex.end())
		//	{
		//		break;
		//	}
		//	auto a = aa._Coro.promise()._Value;
		//	if (*a <= 0)
		//	{
		//		break;
		//	}
		//	printf("" + *a);
		//}
		//delete aaa;
		//ex.begin();
		//ex.begin();
		//ex.begin();
		//ex.begin();
		//ex.begin();

		while (!m_quit) 
		{
			if (ProcessMessage() != 0) 
			{
				break;
			}
			ClearDrawScreen();

			sceneControl->Update();
			sceneControl->Draw();

			ScreenFlip();
		}
		DxLib_End();
	}
	SceneControl* Supervision::GetSceneControl()
	{
		return m_pSceneControl;
	}
}