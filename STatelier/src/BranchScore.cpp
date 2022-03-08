#include "BranchScore.h"

#include <BPM.h>
#include <Note.h>
#include <ScoreInnerInfo.h>

namespace STatelier::Score
{
	void BranchScore::Init(ScoreInnerInfo* pInnerInfo)
	{
		m_startMillisec = pInnerInfo->pivotMillisec;
		AddBPM(pInnerInfo->pBPM);
		AddMeasure(pInnerInfo->pMeasure);
	}
	void BranchScore::Build()
	{

	}
	void BranchScore::AddNote(Note* pNote)
	{
		m_pNoteList.push_back(pNote);
	}
	void BranchScore::AddMeasure(Measure* pMeasure)
	{
		m_pMeasureList.push_back(pMeasure);
	}
	void BranchScore::AddBPM(BPM* pBPM)
	{
		m_pBPMList.push_back(pBPM);
	}
	BPM* BranchScore::GetFirstBPM()
	{
		return *m_pBPMList.begin();
	}
	BPM* BranchScore::GetLastBPM()
	{
		return *m_pBPMList.rbegin();
	}
	Measure* BranchScore::GetFirstMeasure()
	{
		return *m_pMeasureList.begin();
	}
	Measure* BranchScore::GetLastMeasure()
	{
		return *m_pMeasureList.rbegin();
	}
}