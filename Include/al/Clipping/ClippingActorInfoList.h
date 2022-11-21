#pragma once

#include <sead/container/seadPtrArray.h>

namespace al {

class ClippingActorInfo;
class ClippingActorInfoList {
    sead::PtrArray<ClippingActorInfo> mInfos;

public:
    ClippingActorInfoList(int);
};

} // namespace al
