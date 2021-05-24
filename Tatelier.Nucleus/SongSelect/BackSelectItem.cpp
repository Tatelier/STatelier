#include "BackSelectItem.h"

namespace Tatelier::SongSelect {

	SongSelectItemType BackSelectItem::GetType()
	{
		return SongSelectItemType::Back;
	}

	const std::string& BackSelectItem::GetMainTitle()
	{
		return "–ß‚é";
	}
}