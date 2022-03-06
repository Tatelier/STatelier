#pragma once

#include <NoteType.h>
#include <Millisec.h>

namespace STatelier::Score
{
	class BPM;
	class ScoreInnerInfo;

	class Note
	{
	public:
		Note();
		void Init(NoteType noteType, ScoreInnerInfo* innerInfo);

		NoteType GetNoteType();
		const BPM* GetBPM();
		void SetBPM(BPM* bpm);

	private:
		NoteType m_noteType;

		BPM* m_bpm;
		Note* m_pPrevNote;
		Millisec m_startMillisec;
		Millisec m_finishMillisec;
	};

}