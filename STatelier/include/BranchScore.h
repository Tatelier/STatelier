#pragma once

#include <vector>
#include <Millisec.h>
#include <BranchType.h>

namespace STatelier::Score
{
	class ScoreInnerInfo;
	class BPM;
	class Measure;
	class Note;

	class BranchScore
	{
	public:
		void Init(ScoreInnerInfo* innerInfo);
		void Build();
		void AddNote(Note* pNote);
		void AddMeasure(Measure* pMeasure);
		void AddBPM(BPM* pBPM);
		BPM* GetFirstBPM();
		BPM* GetLastBPM();
	private:
		BranchType m_branchType;
		Millisec m_startMillisec;
		Millisec m_finishMillisec;
		
		std::vector<BPM*> m_pBPMList;
		std::vector<Measure*> m_pMeasureList;
		std::vector<Note*> m_pNoteList;
	};
}