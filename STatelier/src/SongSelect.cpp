#include <SongSelect.h>

#include <SceneCommon.h>

#include <SelectItemControl.h>

#include <Player.h>

#include <DxLib.h>

using namespace STatelier;
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
		InitPlayers();

		// •ˆ–Ê“Çž
		{
			auto selectItemControl = new SelectItemControl();

			auto futuref = std::async(std::launch::async, [selectItemControl] {
				selectItemControl->Load("Resources\\Score\\Root");
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
					break;
				}
			}

			this->selectItemControl = selectItemControl;
		}



		co_return;
	}

	void SongSelect::UpdatePlayer(Player* player)
	{
		if (player->GetInput()->GetKeyDown(KEY_INPUT_D))
		{
			selectItemControl->MovePrev();
		}

		if (player->GetInput()->GetKeyDown(KEY_INPUT_K))
		{
			selectItemControl->MoveNext();
		}
	}

	void SongSelect::Update()
	{
		for (size_t i = 0; i < playerList.size(); i++)
		{
			Player* player = playerList[i];

			UpdatePlayer(player);
		}
	}
	void SongSelect::Draw()
	{
		auto current = selectItemControl->GetCurrent();
		if (current == nullptr)
		{

		}
		else
		{
		}
	}

	SongSelect::SongSelect()
	{
		selectItemControl = nullptr;
	}

	SongSelect::~SongSelect()
	{
	}

	IInput* SongSelect::CreatePlayerInput()
	{
		PlayerInput* input = this->playerInputFactory.Create();
		input->SetBaseInput(this->inputFactory.Create());

		int left[] = { KEY_INPUT_D };
		int right[] = { KEY_INPUT_K };

		input->SetLeftInput(left, left + 1);
		input->SetRightInput(right, right + 1);

		return input;
	}

	void SongSelect::InitPlayers()
	{
		this->inputFactory.Init(Supervision::GetInstance()->GetInputControl());
		this->playerFactory.Init();
		this->playerInputFactory.Init();

		playerList.clear();

		for (size_t i = 0; i < 1; i++)
		{
			Player* player = this->playerFactory.Create();
			player->SetInput(CreatePlayerInput());
			playerList.push_back(player);
		}
	}
}