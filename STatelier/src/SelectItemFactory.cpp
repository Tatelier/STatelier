#include "SelectItemFactory.h"

#include <MusicalScoreSelectItem.h>

namespace STatelier::SongSelect
{
	std::shared_ptr<MusicalScoreSelectItem> SelectItemFactory::CreateMusicalScroreSelectItem()
	{
		return std::make_shared<MusicalScoreSelectItem>();
	}
}