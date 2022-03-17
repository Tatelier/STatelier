#include "MusicalScoreSelectItem.h"

#include <MusicalScore.h>
#include <DxLib_u8.h>

using namespace STatelier::Score;

namespace STatelier::SongSelect
{
	void MusicalScoreSelectItem::SetBase(std::shared_ptr<MusicalScore> musicalScore)
	{
		this->m_musicalScore = musicalScore;
	}
	const std::shared_ptr<MusicalScore> MusicalScoreSelectItem::GetBase()
	{
		return this->m_musicalScore;
	}
	void MusicalScoreSelectItem::SetGenre(std::shared_ptr<GenreSelectItem> genre)
	{
		m_genre = genre;
	}
	const std::shared_ptr<GenreSelectItem> MusicalScoreSelectItem::GetGenre()
	{
		return m_genre;
	}
	MusicalScoreSelectItem::~MusicalScoreSelectItem()
	{

	}
	void MusicalScoreSelectItem::Draw(const SelectDrawItem* drawItem)
	{
		DrawRotaStringFToHandle(drawItem->cx, drawItem->cy, 1.0, 1.0, 0, 0, 0, 0xFFFFFF, GetDefaultFontHandle(), 0, 0, (const TCHAR*)GetBase()->GetTitle().c_str());
	}
}