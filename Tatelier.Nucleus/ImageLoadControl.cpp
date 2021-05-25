#include "ImageLoadControl.h"

#include <windows.h>
#include <gdiplus.h>

#include <algorithm>
#include <vector>

#include "DxLib.h"


namespace Tatelier {

	ImageLoadControl& ImageLoadControl::GetInstance()
	{
		static ImageLoadControl instance;

		return instance;
	}

	int ImageLoadControl::Load(const char* path)
	{
		return LoadGraph(path);
	}

	int ImageLoadControl::Load(const std::string& path)
	{
		return Load(path.c_str());
	}

}