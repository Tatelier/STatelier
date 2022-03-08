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
		NoteType m_noteType = NoteType::None;

		BPM* m_bpm = nullptr;
		Note* m_pPrevNote = nullptr;
		Millisec m_startMillisec = 0;
		Millisec m_finishMillisec = 0;
	};

}