#pragma once

#include "../ttle.h"

using namespace ttle;

namespace Tatelier::SongSelect {

	class GenreControl {
	public:
		GenreControl();
		TLRESULT Init(const std::string& filePath);
	private:
		std::string imageRootFolder;
	};
}