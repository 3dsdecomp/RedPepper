#include "al/Util/JMapInfo.h"

#pragma O3
JMapInfo::JMapInfo()
    : mData(nullptr)
    , mName("Undifined")
{
}

bool JMapInfo::attach(const void* data)
{
    if (!data)
        return false;

    mData = JMapData::fromData(data);
    return true;
}
