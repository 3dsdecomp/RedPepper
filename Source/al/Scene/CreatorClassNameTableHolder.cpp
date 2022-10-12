#include "al/Scene/CreatorClassNameTableHolder.h"
#include "al/System/Byaml/ByamlIter.h"
#include "al/System/Resource.h"

namespace al {

#ifdef NON_MATCHING // vtable loc, operator new nullptr check
CreatorClassNameTableHolder::CreatorClassNameTableHolder()
    : mArchive(nullptr)
    , mTable(nullptr)
{
    mArchive = al::findOrCreateResource("SystemData/CreatorClassNameTable", "SystemData/CreatorClassNameTable");
    mTable = new ByamlIter(static_cast<const u8*>(mArchive->getByml("CreatorClassNameTable")));
}
#endif

} // namespace al
