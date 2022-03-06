#include <SongSelect.h>

#include <SelectItemControl.h>

#include <DxLib.h>

using namespace STatelier::SongSelect;

namespace
{
}

namespace STatelier::Scene
{
	int32_t SongSelect::PreStart()
	{
		return 0;
	}

	std::experimental::generator<void*> SongSelect::GetStartIterator()
	{
		auto selectItemControl = new SelectItemControl();

		auto futuref = std::async(std::launch::async, [selectItemControl] {
			selectItemControl->Load("R:\\C#\\Tatelier\\Tatelier\\bin\\x64\\Debug\\Resources\\Score\\Root");
		});

		while (true)
		{
			auto status = futuref.wait_for(std::chrono::milliseconds(0));

			if (status != std::future_status::ready)
			{
				co_yield nullptr;
			}
			else
			{
				selectItemControlStatus = true;
				break;
			}
		}

		co_return;
	}

	void SongSelect::Update()
	{
	}
	void SongSelect::Draw()
	{
		if (selectItemControlStatus)
		{
			DrawString(0, 0, "DONE!!", 0xFFFFFF);
		}
	}
}