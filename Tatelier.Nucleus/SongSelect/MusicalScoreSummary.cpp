#include "MusicalScoreSummary.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "../Utility.h"

namespace Tatelier::SongSelect {

	MusicalScoreSummary::MusicalScoreSummary(const std::string& rootFolder, const std::string& relativeFilePath) 
		: MusicalScoreSummary::MusicalScoreSummary(ttlePathCombineString(rootFolder, relativeFilePath))
	{
	}

	MusicalScoreSummary::MusicalScoreSummary(const std::string& filePath)
	{
		std::string text;

		ttleFileAllText(filePath, &text);

		EncodingType type = ttleGetEncodingType(text);
	}
}