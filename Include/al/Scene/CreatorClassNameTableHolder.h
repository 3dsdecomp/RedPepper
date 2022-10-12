#pragma once

#include "al/System/Byaml/ByamlIter.h"
#include "al/System/Resource.h"

namespace al {

class CreatorClassNameTableHolder {
    Resource* mArchive;
    ByamlIter* mTable;

public:
    CreatorClassNameTableHolder();

    // CreateActorFunctionT getCreator(const char* objectName) const;
};

} // namespace al
