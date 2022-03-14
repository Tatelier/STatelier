#include "..\include\Note.h"
#include <ScoreInnerInfo.h>

namespace STatelier::Score
{
	Note::Note()
	{
	}
	void Note::Init(NoteType noteType, ScoreInnerInfo* innerInfo)
	{
		m_noteType = noteType;
		m_startMillisec = innerInfo->pivotMillisec;
		m_finishMillisec = m_startMillisec;
		SetBPM(innerInfo->pBPM);
	}
	NoteType Note::GetNoteType()
	{
		return m_noteType;
	}
	const BPM* Note::GetBPM()
	{
		return m_bpm;
	}
	void Note::SetBPM(BPM* bpm)
	{
		m_bpm = bpm;
	}
}