#pragma once

#include <cstdint>

#include <string>

#include "../ttle.h"

namespace Tatelier::SongSelect {

	class ItemControl2 {
	public:
		ItemControl2();
		uint32_t Init(const std::string& scoreFolderPath);
	private:
		const std::string rootFolderName = "Root";
		const std::string searchFilterExtensions = ".tja|.pts";
	};
}