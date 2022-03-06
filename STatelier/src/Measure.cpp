#include "..\include\Measure.h"


namespace STatelier::Score
{
	Measure::Measure()
	{

	}
	void Measure::Init(DetailedMillisec detailedMillisec, double upper, double lower)
	{
		m_upper = upper;
		m_lower = lower;
		m_startMillisec = ToMillisec(detailedMillisec);
	}
	double Measure::GetMeasureValue()
	{
		return m_upper * 4 / m_lower;
	}
	double Measure::GetCalc(double val)
	{
		return val * m_upper * 4 / m_lower;
	}
	const Millisec Measure::GetStartMillisec()
	{
		return m_startMillisec;
	}
	const Millisec Measure::GetFinishMillisec()
	{
		return m_finishMillisec;
	}
	void Measure::SetFinishMillisec(DetailedMillisec detailedMillisec)
	{
		m_finishMillisec = ToMillisec(detailedMillisec);
	}
}