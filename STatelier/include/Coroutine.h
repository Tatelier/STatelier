#pragma once
#include <experimental/generator>
#include <functional>

#include <Factory.h>

namespace STatelier
{
	class IScene;

	class Coroutine
	{
	public:
		Coroutine()
		{
		}
		void* Update();
		bool IsEnabled()
		{
			return m_enabled;
		}
		void SetEnabled(bool enabled)
		{
			m_enabled = enabled;
		}
		std::experimental::generator<void*> m_generator;
		IScene* m_scene;
		std::function<void(int, Coroutine*)> m_callback;
	private:
		bool m_enabled = true;
	};
	class CoroutineControl
	{
	public:
		Coroutine* Create()
		{
			auto pInstance = m_coroutineFactory.Create();

			return pInstance;
		}
		Coroutine* StartCoroutine(Coroutine* pCoroutine)
		{
			return pCoroutine;
		}
		void DestoryCoroutine(Coroutine* pCoroutine)
		{
			m_coroutineFactory.Destory(pCoroutine);
		}
		void Update()
		{
			for (size_t i = 0; i < m_coroutineFactory.GetList().size(); i++)
			{
				Coroutine* coroutine = m_coroutineFactory.GetList()[i];

				if (coroutine->IsEnabled())
				{
					void* result = coroutine->Update();

					if ((int)result == -1)
					{
						coroutine->m_callback(0, coroutine);
						if (m_coroutineFactory.Destory(coroutine) == 0)
						{
							i--;
						}
					}
				}
			}
		}
	private:
		Factory<Coroutine> m_coroutineFactory;
	};

}