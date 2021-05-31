#pragma once

#include <string>

#include "../ttle.h"

using namespace ttle;

namespace Tatelier::SongSelect {
	class Course {
	public:
		const std::string& GetName();
		TLRESULT SetName(const std::string name);

		float GetLevel();
		TLRESULT SetLevel(float level);

		bool HasBranch();
		TLRESULT SetHasBranch(bool hasBranch);

	private:
		std::string name = "Oni";

		float level = -1;

		bool hasBranch = false;
	};
}