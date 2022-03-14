#pragma once
#include <IScene.h>
#include <player.h>
#include <Factory.h>
#include <InputFactory.h>

namespace STatelier
{
	class IInput;
}

namespace STatelier::SongSelect
{
	class SelectItemControl;
	//class Player;
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
		SongSelect();
		~SongSelect();
	private:
		void InitPlayers();

		IInput* CreatePlayerInput();

		SelectItemControl* selectItemControl = nullptr;

		std::vector<Player*> playerList;

		InputFactory inputFactory;

		Factory<Player> playerFactory;
		Factory<PlayerInput> playerInputFactory;
	};
}