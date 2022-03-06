#pragma once

#include <memory>
#include <vector>

namespace STatelier::SongSelect
{
	class ISelectItem;

	using ISelectItemList = std::vector<std::shared_ptr<ISelectItem>>;

	class ISelectItem
	{
	public:
		std::shared_ptr<ISelectItem> GetPrev()
		{
			return m_prev;
		}
		void SetPrev(std::shared_ptr<ISelectItem> prev)
		{
			m_prev = prev;
		}
		std::shared_ptr<ISelectItem> GetNext()
		{
			return m_next;
		}
		void SetNext(std::shared_ptr<ISelectItem> next)
		{
			m_next = next;
		}

		virtual ~ISelectItem()
		{

		}
	private:
		std::shared_ptr<ISelectItem> m_parent;
		std::shared_ptr<ISelectItem> m_prev;
		std::shared_ptr<ISelectItem> m_next;
	};
}