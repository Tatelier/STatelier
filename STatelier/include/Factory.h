#pragma once

#include <vector>

namespace STatelier
{
	template<class T>
	class Factory
	{
	public:
		T* Create()
		{
			T* pInstance = new T();

			m_instanceList.push_back(pInstance);

			return pInstance;
		}
		int Destory(T* pInstance)
		{
			auto position = std::find(m_instanceList.begin(), m_instanceList.end(), pInstance);
			if (position != m_instanceList.end())
			{
				m_instanceList.erase(position);
				return 0;
			}
			return -1;
		}
		const std::vector<T*> GetList()
		{
			return m_instanceList;
		}
		~Factory()
		{
			for (size_t i = 0; i < m_instanceList.size(); i++)
			{
				delete m_instanceList[i];
			}
		}
	private:
		std::vector<T*> m_instanceList;
	};
}