#pragma once
#include <IScene.h>

namespace STatelier
{
	class IInput;
}

namespace STatelier::SongSelect
{
	class SelectItemControl;
}

namespace STatelier::Scene
{
	class SongSelect : public IScene
	{
	public:
		virtual int32_t PreStart() override;
		virtual std::experimental::generator<void*> GetStartIterator() override;
		virtual void Update() override;
		virtual void Draw() override;
	private:
		bool selectItemControlStatus = false;
		SelectItemControl* selectItemControl;
		IInput* input;
	};
}