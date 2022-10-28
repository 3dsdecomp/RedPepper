#include "al/Factory/ActorFactory.h"
#include "al/System/Byaml/ByamlIter.h"

namespace al {

#ifdef NON_MATCHING // unnecessary streq for mConvertNameData missing
ActorFactory::ActorFactory()
    : mArchive(nullptr)
    , mConvertNameData(nullptr)
{
    mArchive = al::findOrCreateResource("SystemData/CreatorClassNameTable");
    mConvertNameData = new ByamlIter(static_cast<const u8*>(mArchive->getByml("CreatorClassNameTable")));
}
#endif

} // namespace al
