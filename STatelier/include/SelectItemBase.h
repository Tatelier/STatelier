#pragma once

#include <memory>
#include <vector>

namespace STatelier::SongSelect
{
	class SelectItemBase;

	using ISelectItemList = std::vector<std::shared_ptr<SelectItemBase>>;

	class SelectItemBase
	{
	public:
		std::shared_ptr<SelectItemBase> GetPrev()
		{
			return m_prev;
		}
		void SetPrev(std::shared_ptr<SelectItemBase> prev)
		{
			m_prev = prev;
		}
		std::shared_ptr<SelectItemBase> GetNext()
		{
			return m_next;
		}
		void SetNext(std::shared_ptr<SelectItemBase> next)
		{
			m_next = next;
		}

		virtual ~SelectItemBase()
		{

		}
	private:
		std::shared_ptr<SelectItemBase> m_parent;
		std::shared_ptr<SelectItemBase> m_prev;
		std::shared_ptr<SelectItemBase> m_next;
	};
}