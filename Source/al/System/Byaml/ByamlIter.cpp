#include "al/System/Byaml/ByamlIter.h"

namespace al {

ByamlIter::ByamlIter()
    : mData(nullptr)
    , mRootNode(nullptr)
{
}

ByamlIter::ByamlIter(const u8* data)
    : mData(data)
    , mRootNode(nullptr)
{
    if (mData) {
        if (!alByamlLocalUtil::verifiByaml(data)) {
            mData = nullptr;
            mRootNode = nullptr;
            return;
        }
        int offset = mHeader->getDataOffset();
        if (offset != 0)
            mRootNode = mData + this->mHeader->getDataOffset();
    }
}

int ByamlIter::getSize() const
{
    if (mContainerHeader && isTypeContainer())
        return mContainerHeader->getCount();
    return 0;
}

} // namespace al
