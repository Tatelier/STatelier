#include <SongSelect.h>

#include <SceneCommon.h>

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
			selectItemControl->Load("Resources\\Score\\Root");
		});

		this->selectItemControl = selectItemControl;

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

		input = Supervision::GetInstance()->GetInputControl()->CreateInput();

		co_return;
	}
	int a = 0;
	void SongSelect::Update()
	{
		a = input->GetCount(KEY_INPUT_D);
	}
	void SongSelect::Draw()
	{
		auto current = selectItemControl->GetCurrent();
		if (current == nullptr)
		{
			DrawString(0, 0, "•ˆ–Ê‚ª‘¶İ‚µ‚Ü‚¹‚ñB", 0xFFFFFF, 0);
		}
		else
		{
			auto ms = std::dynamic_pointer_cast<MusicalScoreSelectItem>(current);
			DrawString(0, 0, (ms->GetBase()->GetTitle() + std::to_string(a)).c_str(), 0xFFFFFF, 0);
		}
	}
}