#pragma once

#include <cstdint>
#include <future>
#include <coroutine>
#include <experimental/generator>

#include <SelectItemControl.h>

using namespace STatelier::SongSelect;

namespace STatelier
{
	class IScene
	{
	public:
		virtual int32_t PreStart() = 0;
		virtual std::experimental::generator<void*> GetStartIterator() = 0;

		virtual void Update() { }
		virtual void Draw() { }
		virtual void Finish() { }
	private:
	};
}