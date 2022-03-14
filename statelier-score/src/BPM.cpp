
#include <BPM.h>

namespace STatelier::Score
{
	const DetailedMillisec BPM::InitStartMillisec = -60.0 * 1000;

	void BPM::Init(DetailedMillisec detailedMillisec, double bpm)
	{
		m_value = bpm;
		m_startMillisec = ToMillisec(detailedMillisec);
	}

	BPM::BPM()
	{

	}

	double BPM::GetValue() const
	{
		return m_value;
	}

	Millisec BPM::GetStartMillisec() const
	{
		return m_startMillisec;
	}

	Millisec BPM::GetFinishMillisec() const
	{
		return m_finishMillisec;
	}
	
	void BPM::SetFinishMillisec(DetailedMillisec detailedMillisec)
	{
		m_finishMillisec = ToMillisec(detailedMillisec);
	}
}