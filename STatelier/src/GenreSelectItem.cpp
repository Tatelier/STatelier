#include "..\include\GenreSelectItem.h"


namespace STatelier::SongSelect
{
	GenreSelectItem::GenreSelectItem()
	{
		m_children = std::make_shared<ISelectItemList>(0);
	}
	GenreSelectItem::~GenreSelectItem()
	{
		m_children->clear();
	}
}