#pragma once

#include <Millisec.h>

namespace STatelier::Score
{
	class Measure
	{
	public:
		Measure();
		void Init(DetailedMillisec detailedMillisec, double upper, double lower);

		double GetMeasureValue();
		double GetCalc(double val);
		const Millisec GetStartMillisec();
		const Millisec GetFinishMillisec();
		void SetFinishMillisec(DetailedMillisec detailedMillisec);
	private:
		double m_upper = 4;
		double m_lower = 4;
		Millisec m_startMillisec = -60 * 1000;
		Millisec m_finishMillisec = 60 * 60 * 1000;
	};
}