#pragma once

#include <Millisec.h>
#include <functional>

namespace STatelier::Score
{
	class Measure;
	class BranchScore;

	class ScoreInnerInfo
	{
	public:
		struct FunctionTableItem
		{
			std::string name;
			std::function<int(ScoreInnerInfo*, const std::string&)> func;

			FunctionTableItem()
			{

			}
			FunctionTableItem(std::string name, std::function<int(ScoreInnerInfo*, const std::string&)> func)
			{
				this->name = name;
				this->func = func;
			}
		};
		static const DetailedMillisec InitPivotMillisec;
		BPM* pBPM;
		Measure* pMeasure;
		BranchScore* pBranchScore;
		DetailedMillisec pivotMillisec = 0.0;
		Note* prevNote;
		std::vector<FunctionTableItem> functionTable;
	};
}