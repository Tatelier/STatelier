#pragma once

#include <queue>
#include <experimental/generator>

#include "IScene.h"

#include <Coroutine.h>

namespace STatelier 
{
	struct A
	{
		IScene* scene;
		std::experimental::generator<int> a;
	};
	class SceneControl
	{
	public:
		void Start();
		void Update();
		void Draw();
		void Finish();
		template <typename T> T* CreateScene();
	private:
		std::vector<IScene*> m_pSceneList;
		CoroutineControl m_coroutineControl;
	};
}
