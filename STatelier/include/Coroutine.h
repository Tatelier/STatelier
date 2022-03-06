#pragma once
#include <experimental/generator>
#include <functional>

#include <Factory.h>

namespace STatelier
{
	class Coroutine
	{
	public:
		Coroutine()
		{
		}
		void* Update()
		{
			const auto& iterator = m_generator.begin();

			if (!iterator._Coro)
			{
				return (void*)-1;
			}
			auto promise = iterator._Coro.promise();

			return (void*)*promise._Value;
		}
		bool IsEnabled()
		{
			return m_enabled;
		}
		void SetEnabled(bool enabled)
		{
			m_enabled = enabled;
		}
		std::experimental::generator<void*> m_generator;
		std::function<int(void*)> m_callback;
	private:
		bool m_enabled;
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