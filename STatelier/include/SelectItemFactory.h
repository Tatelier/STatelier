#pragma once

#include <memory>
#include <string>

namespace STatelier::SongSelect
{
	class MusicalScoreSelectItem;

	class SelectItemFactory
	{
	public:
		std::shared_ptr<MusicalScoreSelectItem> CreateMusicalScroreSelectItem();
	};
}