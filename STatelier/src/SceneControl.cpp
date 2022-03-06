#include "SceneControl.h"

#include <SongSelect.h>

namespace STatelier
{
	void SceneControl::Start()
	{
		auto scene = CreateScene<Scene::SongSelect>();
		scene->PreStart();
		Coroutine* coroutine = m_coroutineControl.Create();

		coroutine->m_generator = scene->GetStartIterator();

		m_coroutineControl.StartCoroutine(coroutine);

		m_pSceneList.push_back(scene);
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

	template <typename T> 
	T* SceneControl::CreateScene()
	{
		auto a = new T();
		m_pSceneList.push_back(a);

		return a;
	}

}