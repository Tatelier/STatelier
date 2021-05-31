#include "Course.h"

TLRESULT Tatelier::SongSelect::Course::SetName(const std::string name)
{
    this->name = name;
    return TL_SUCCESS;
}

float Tatelier::SongSelect::Course::GetLevel()
{
    return level;
}

TLRESULT Tatelier::SongSelect::Course::SetLevel(float level)
{
    this->level = level;

    return TL_SUCCESS;
}

bool Tatelier::SongSelect::Course::HasBranch()
{
    return hasBranch;
}

TLRESULT Tatelier::SongSelect::Course::SetHasBranch(bool hasBranch)
{
    this->hasBranch = hasBranch;

    return TL_SUCCESS;
}
