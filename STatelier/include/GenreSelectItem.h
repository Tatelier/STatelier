#pragma once

#include <SelectItemBase.h>

namespace STatelier::SongSelect
{
	class GenreSelectItem
		: public SelectItemBase
	{
	public:
		GenreSelectItem();
		virtual ~GenreSelectItem() override;

		std::shared_ptr<SelectItemBase> GetCurrent()
		{
			if (m_children->size() > m_currentIndex)
			{
				return m_children->at(m_currentIndex);
			}
			else
			{
				return nullptr;
			}
		}

		std::shared_ptr<ISelectItemList> GetChildren()
		{
			return m_children;
		}
	private:
		std::shared_ptr<ISelectItemList> m_children;
		std::int32_t m_currentIndex = 0;
	};
}