#pragma once

#include <memory>
#include <string>
#include <vector>
#include <filesystem>
#include "MusicalScoreSelectItem.h"
#include <GenreSelectItem.h>
#include "SelectItemFactory.h"
#include "SelectItemControl.h"
#include "MusicalScoreFactory.h"

using namespace STatelier::Score;

namespace STatelier::SongSelect
{
	class SelectItemControl
	{
	public:
		std::shared_ptr<SelectItemBase> GetCurrent()
		{
			return m_current;
		}
		int Open()
		{
			if (m_current != nullptr)
			{
				auto genre = std::dynamic_pointer_cast<GenreSelectItem>(m_current);
				if (genre != nullptr)
				{
					auto current = genre->GetCurrent();
					if (current != nullptr)
					{
						m_current = current;
						return 0;
					}
					else
					{
						return -2;
					}
				}
				else
				{
					return -3;
				}
			}

			return -1;
		}
		int MovePrev()
		{
			if (m_current != nullptr)
			{
				m_current = m_current->GetPrev();
				return 0;
			}
			return -1;
		}
		int MoveNext()
		{
			if (m_current != nullptr)
			{
				m_current = m_current->GetNext();
				return 0;
			}
			return -1;
		}
		int Load(const std::string& folderPath)
		{
			using std::filesystem::recursive_directory_iterator;

			SelectItemFactory selectItemFactory;
			MusicalScoreFactory musicalScoreFactory;

			if (!std::filesystem::exists(folderPath))
			{
				return -1;
			}

			// 譜面データを取得
			for (const auto& file : recursive_directory_iterator(folderPath))
			{
				auto path = file.path();

				if (path.extension() == ".tja"
					|| path.extension() == ".pts")
				{
					std::shared_ptr<STatelier::Score::MusicalScore> musicalScore = musicalScoreFactory.Create();
					musicalScore->Load(path.string());

					m_musicalScoreList->push_back(musicalScore);
				}
			}


			// 選曲用項目を生成
			for (size_t i = 0; i < m_musicalScoreList->size(); i++)
			{
				std::shared_ptr<MusicalScore> ms = m_musicalScoreList->at(i);

				auto msSelectItem = selectItemFactory.CreateMusicalScroreSelectItem();

				msSelectItem->SetBase(ms);

				m_selectItemList->push_back(msSelectItem);
			}

			// 前後関係を設定
			for (size_t i = 0; i < m_selectItemList->size(); i++)
			{
				m_selectItemList->at(i)->SetPrev(m_selectItemList->at((i + (m_selectItemList->size() - 1)) % m_selectItemList->size()));
				m_selectItemList->at(i)->SetNext(m_selectItemList->at((i + 1) % m_selectItemList->size()));
			}

			if (m_selectItemList->size() > 0)
			{
				m_current = m_selectItemList->at(0);
			}
			return 0;
		}
		SelectItemControl()
		{
			m_musicalScoreList = std::make_shared<std::vector<std::shared_ptr<MusicalScore>>>();
			m_selectItemList = std::make_shared<std::vector<std::shared_ptr<SelectItemBase>>>();
		}
		~SelectItemControl()
		{
			m_musicalScoreList->clear();
			m_selectItemList->clear();
		}
	private:
		std::shared_ptr<std::vector<std::shared_ptr<MusicalScore>>> m_musicalScoreList;
		std::shared_ptr<std::vector<std::shared_ptr<SelectItemBase>>> m_selectItemList;

		std::shared_ptr<SelectItemBase> m_current;
	};

}