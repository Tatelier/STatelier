#pragma once

#include <ISelectItem.h>

namespace STatelier::SongSelect
{
	class GenreSelectItem
		: public ISelectItem
	{
	public:
		GenreSelectItem();
		virtual ~GenreSelectItem() override;

		std::shared_ptr<ISelectItemList> GetChildren()
		{
			return m_children;
		}
	private:
		std::shared_ptr<ISelectItemList> m_children;
	};
}