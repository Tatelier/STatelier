#pragma once

#include <memory>

#include <MusicalScore.h>

namespace STatelier::Score
{
	class MusicalScoreFactory
	{
	public:
		std::shared_ptr<MusicalScore> Create()
		{
			return std::make_shared<MusicalScore>();
		}

		MusicalScoreFactory()
		{

		}
		~MusicalScoreFactory()
		{

		}
	private:

	};

}