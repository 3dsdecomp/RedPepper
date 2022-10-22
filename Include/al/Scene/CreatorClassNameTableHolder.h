#pragma once

#include "al/Resource/Resource.h"
#include "al/System/Byaml/ByamlIter.h"

namespace al {

class CreatorClassNameTableHolder {
    Resource* mArchive;
    ByamlIter* mTable;

public:
    CreatorClassNameTableHolder();

    // CreateActorFunctionT getCreator(const char* objectName) const;
};

} // namespace al
