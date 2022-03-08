#include "SceneControl.h"

#include <SongSelect.h>

namespace
{
}

namespace STatelier
{

	void SceneControl::Start()
	{
		auto scene = CreateScene<Scene::SongSelect>();
		scene->PreStart();
		Coroutine* coroutine = m_coroutineControl.Create();

		coroutine->m_scene = scene;
		coroutine->m_generator = scene->GetStartIterator();
		coroutine->m_callback = std::bind(&SceneControl::Callback, this, std::placeholders::_1, std::placeholders::_2);

		m_coroutineControl.StartCoroutine(coroutine);
	}

	void SceneControl::Update()
	{
		m_coroutineControl.Update();
		for (size_t i = 0; i < m_pSceneList.size(); i++)
		{
			m_pSceneList[i]->Update();
		}
	}
	void SceneControl::Draw()
	{
		for (size_t i = 0; i < m_pSceneList.size(); i++)
		{
			m_pSceneList[i]->Draw();
		}
	}
	void SceneControl::Finish()
	{
	}
	void SceneControl::Callback(int result, STatelier::Coroutine* coroutine)
	{
		m_pSceneList.push_back(coroutine->m_scene);
	}

	template <typename T> 
	T* SceneControl::CreateScene()
	{
		auto a = new T();

		return a;
	}

}