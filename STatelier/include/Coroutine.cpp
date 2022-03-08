#include "Coroutine.h"

namespace STatelier
{
	void* Coroutine::Update()
	{
		const auto& iterator = m_generator.begin();

		if (!iterator._Coro)
		{
			return (void*)-1;
		}
		auto promise = iterator._Coro.promise();

		return (void*)*promise._Value;
	}
}