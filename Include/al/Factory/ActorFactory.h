#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/Resource/Resource.h"
#include "al/System/Byaml/ByamlIter.h"

namespace al {

typedef LiveActor* (*CreateActorFuncPtr)(const char* objectName);

class ActorFactory {
    Resource* mArchive;
    ByamlIter* mConvertNameData;

public:
    ActorFactory();

    const char* convertName(const char* objectName) const;
    CreateActorFuncPtr getCreator(const char* objectName) const;
};

} // namespace al
