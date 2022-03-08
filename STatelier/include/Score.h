#pragma once

#include <memory>

#include <Millisec.h>
#include <BPM.h>
#include <Measure.h>
#include <Factory.h>
#include "CourseType.h"
#include <BranchScore.h>
#include <ScoreInnerInfo.h>

#include <Note.h>

#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include <experimental/generator>

namespace STatelier::Score
{
	class NoteControl
	{
	public:
		std::vector<std::vector<std::vector<Note>>> noteList;
	};

	struct ScoreInfo
	{
		CourseType courseType = CourseType::VeryHardA;
		double level = -1.0;
		double startBPM = 120;
		DetailedMillisec offsetMillisec = 0;
		std::vector<int> balloonCountList;
		int lineCount;
		std::ifstream* p_ifs;
	};


	class Score
	{
	public:
		int Load(ScoreInfo* info);
		Score();
		~Score();
	private:
		double m_level = -1;
		double m_startBPM = 120;

		Millisec m_offsetMillisec;

		std::shared_ptr<std::vector<int>> m_balloonCountList;

		Factory<BranchScore> m_branchScoreFactory;
		Factory<BPM> m_bpmFactory;
		Factory<Measure> m_measureFactory;
		Factory<Note> m_noteFactory;

		int GetNoteCount(const std::vector<std::string>& list);
		std::string replace_first(const std::string& replacedStr, std::string from, std::string to);

		bool TryGetValue(const std::string& line, const std::vector<ScoreInnerInfo::FunctionTableItem>& funcList, ScoreInnerInfo::FunctionTableItem* pFuncInfo);
		bool TryGetValue(const std::string& line, const std::string& name, std::string* val);
		
		int SetBPMCHANGE(ScoreInnerInfo* innerInfo, const std::string& args);
		int SetMEASURE(ScoreInnerInfo* innerInfo, const std::string& arg);
		
		void OneMeasureLine(const std::vector<std::string>& list, ScoreInnerInfo* innerInfo);
	};
}