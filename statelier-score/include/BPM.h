#pragma once

#include <export.h>
#include "Millisec.h"

namespace STatelier::Score
{
	class BPM
	{
	public:
		static const DetailedMillisec InitStartMillisec;

		BPM();

		void Init(DetailedMillisec detailedMillisec, double bpm);

		double GetValue() const;

		Millisec GetStartMillisec() const;

		Millisec GetFinishMillisec() const;

		void SetFinishMillisec(DetailedMillisec detailedMillisec);
	private:
		double m_value = 120.0;
		Millisec m_startMillisec = InitStartMillisec;
		Millisec m_finishMillisec = 60 * 60 * 1000;
	};


}