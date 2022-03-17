#pragma once

#include <memory>

#include <SelectItemBase.h>

namespace STatelier::Score
{
	class MusicalScore;
}

namespace STatelier::SongSelect
{
	class GenreSelectItem;

	class MusicalScoreSelectItem
		: public SelectItemBase
	{
	public:
		void SetBase(std::shared_ptr<STatelier::Score::MusicalScore> musicalScore);
		const std::shared_ptr<STatelier::Score::MusicalScore> GetBase();

		const std::shared_ptr<GenreSelectItem> GetGenre();
		void SetGenre(std::shared_ptr<GenreSelectItem> genre);

		virtual void Draw(const SelectDrawItem* drawItem) override;

		virtual ~MusicalScoreSelectItem() override;
	private:
		std::shared_ptr<STatelier::Score::MusicalScore> m_musicalScore = nullptr;
		std::shared_ptr<GenreSelectItem> m_genre;

	};
}