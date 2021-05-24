#pragma once

#include "SelectItem.h"

namespace Tatelier::SongSelect {
	class BackSelectItem : public SelectItem {

		virtual SongSelectItemType GetType() override;
		virtual const std::string& GetMainTitle() override;
	};
}
