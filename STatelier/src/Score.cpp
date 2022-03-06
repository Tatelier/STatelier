#include <Score.h>

#include <functional>

namespace STatelier::Score
{
	const DetailedMillisec ScoreInnerInfo::InitPivotMillisec = 0.0;



	int Score::Load(ScoreInfo* info)
	{
		std::function<int(ScoreInnerInfo*, const std::string&)> func1 = std::bind(&Score::SetBPMCHANGE, this, std::placeholders::_1, std::placeholders::_2);

		ScoreInnerInfo innerInfo;

		innerInfo.functionTable.push_back(ScoreInnerInfo::FunctionTableItem("#BPMCHANGE", func1));

		auto& ifs = *info->p_ifs;

		m_offsetMillisec = ToMillisec(info->offsetMillisec);
		m_startBPM = info->startBPM;

		innerInfo.pBranchScore = m_branchScoreFactory.Create();

		innerInfo.pBPM = m_bpmFactory.Create();
		innerInfo.pBPM->Init(innerInfo.pivotMillisec, m_startBPM);

		innerInfo.pMeasure = m_measureFactory.Create();
		innerInfo.pMeasure->Init(innerInfo.pivotMillisec, 4, 4);

		innerInfo.pBranchScore->Init(&innerInfo);

		if (!ifs)
		{
			return -1;
		}

		std::string line;
		std::regex regex("(\\S+):(.+)");
		std::smatch match;

		std::vector<std::string> oneMeasureContent;

		bool isExit = false;

		while (isExit
			|| std::getline(ifs, line))
		{
			info->lineCount++;

			// ÉRÉÅÉìÉgçÌèú
			{
				int pos = line.find("//");
				line = line.substr(0, pos);
			}

			// CRÇçÌèú
			{
				int pos = line.find("\r");
				line = line.substr(0, pos);
			}

			if (line.starts_with("#END"))
			{
				isExit = true;
			}

			if (line.starts_with("#"))
			{
				oneMeasureContent.push_back(line);
			}
			else
			{
				while (line.size() > 0)
				{
					int index = line.find(",");
					if (index == std::string::npos)
					{
						oneMeasureContent.push_back(line);
						line = "";
					}
					else
					{
						oneMeasureContent.push_back(line.substr(0, index));

						// 1è¨êﬂèàóù
						OneMeasureLine(oneMeasureContent, &innerInfo);

						oneMeasureContent.clear();

						size_t nextStartIndex = (size_t)(index + 1);
						line = line.substr(nextStartIndex, line.size() - nextStartIndex);
					}
				}
			}

			// èàóùèIóπ
			if (isExit)
			{
				break;
			}
		}

		return 0;
	}
	Score::Score()
	{
		m_balloonCountList = std::make_shared<std::vector<int>>();
	}
	Score::~Score()
	{
	}
	int Score::GetNoteCount(const std::vector<std::string>& list)
	{
		int noteCount = 0;
		for (const std::string& line : list)
		{
			if (line.starts_with("#"))
			{
				continue;
			}

			for (char c : line)
			{
				if ('0' <= c
					&& c <= '9')
				{
					noteCount++;
				}
			}
		}

		return noteCount;
	}
	std::string Score::replace_first(const std::string& replacedStr, std::string from, std::string to) {
		std::string result = replacedStr;
		const unsigned int pos = replacedStr.find(from);
		const int len = from.length();

		if (pos == std::string::npos || from.empty()) {
			return result;
		}

		return result.replace(pos, len, to);
	}

	bool Score::TryGetValue(const std::string& line, const std::vector<ScoreInnerInfo::FunctionTableItem>& funcList, ScoreInnerInfo::FunctionTableItem* pFuncInfo)
	{
		for (size_t i = 0; i < funcList.size(); i++)
		{
			if (line.starts_with(funcList[i].name))
			{
				*pFuncInfo = funcList[i];
				return true;
			}
		}

		return false;
	}

	bool Score::TryGetValue(const std::string& line, const std::string& name, std::string* val)
	{
		if (line.starts_with(name))
		{
			*val = replace_first(line, name, "");

			return true;
		}

		return false;
	}
	int Score::SetBPMCHANGE(ScoreInnerInfo* innerInfo, const std::string& args)
	{
		if (innerInfo->pBPM->GetStartMillisec() == BPM::InitStartMillisec
			&& innerInfo->pivotMillisec == ScoreInnerInfo::InitPivotMillisec)
		{
			innerInfo->pBPM->Init(innerInfo->pivotMillisec, std::stod(args));
			innerInfo->pBranchScore->GetFirstBPM()->Init(innerInfo->pivotMillisec, std::stod(args));
		}
		else
		{
			innerInfo->pBPM = m_bpmFactory.Create();
			innerInfo->pBPM->Init(innerInfo->pivotMillisec, std::stod(args));

			innerInfo->pBranchScore->GetLastBPM()->SetFinishMillisec(innerInfo->pivotMillisec);
			innerInfo->pBranchScore->AddBPM(innerInfo->pBPM);
		}
		return 0;
	}
	void Score::OneMeasureLine(const std::vector<std::string>& list, ScoreInnerInfo* innerInfo)
	{
		DetailedMillisec pivotMillisec = innerInfo->pivotMillisec;


		int noteCount = GetNoteCount(list);

		bool isSharpLine = false;

		for (const std::string& line : list)
		{
			isSharpLine = false;
			if (line.starts_with("#"))
			{
				ScoreInnerInfo::FunctionTableItem funcInfo;

				if (TryGetValue(line, innerInfo->functionTable, &funcInfo))
				{
					std::string arg = replace_first(line, funcInfo.name, "");
					funcInfo.func(innerInfo, arg);
				}
			}
			else
			{
				for (char c : line)
				{
					switch (c)
					{
						case '0':
						case '9':
							{
							}
							break;
						case '1':
						case '2':
						case '3':
						case '4':
						case '5':
						case '6':
						case '7':
						case '8':
							{
								auto note = m_noteFactory.Create();
								note->Init((NoteType)c, innerInfo);
								innerInfo->pBranchScore->AddNote(note);
							}
							break;
					}

					if ('0' <= c
						&& c <= '9')
					{
						double addDiffMillisec = innerInfo->pMeasure->GetCalc(60000) / (innerInfo->pBPM->GetValue() * noteCount);
						innerInfo->pivotMillisec += addDiffMillisec;
					}
				}
			}
		}

		if (noteCount == 0)
		{
			double addDiffMillisec = innerInfo->pMeasure->GetCalc(60000) / (innerInfo->pBPM->GetValue());
			innerInfo->pivotMillisec += addDiffMillisec;
		}
	}
}