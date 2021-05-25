#pragma once

#include <string>

#include <list>
#include <unordered_map>

namespace Tatelier {

	class ImageLoadControl {
	public:
		static ImageLoadControl& GetInstance();
		int Load(const char* path);
		int Load(const std::string& path);


	private:
	};
}