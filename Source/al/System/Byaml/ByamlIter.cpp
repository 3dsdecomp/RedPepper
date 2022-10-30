#include "al/System/Byaml/ByamlIter.h"
#include "al/System/Byaml/ByamlData.h"
#include "al/System/Byaml/ByamlHashIter.h"
#include "al/System/Byaml/ByamlStringTableIter.h"

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

bool ByamlIter::isValid() const { return mData != nullptr; }

int ByamlIter::getSize() const
{
    if (isTypeContainer())
        return mContainerHeader->getCount();
    return 0;
}

bool ByamlIter::isTypeArray() const { return mContainerHeader != nullptr && mContainerHeader->getType() == ByamlDataType_Array; }
bool ByamlIter::isTypeHash() const { return mContainerHeader != nullptr && mContainerHeader->getType() == ByamlDataType_Hash; }
bool ByamlIter::isTypeContainer() const
{
    return mContainerHeader != nullptr && (mContainerHeader->getType() == ByamlDataType_Array || mContainerHeader->getType() == ByamlDataType_Hash);
}

int ByamlIter::getKeyIndex(const char* key) const
{
    ByamlStringTableIter iter(mData + mHeader->getHashKeyTableOffset());
    return iter.findStringIndex(key);
}

#pragma no_inline
NON_MATCHING
bool ByamlIter::getByamlDataByKey(ByamlData* out, const char* key) const
{
    if (isTypeHash()) {
        int keyIndex = getKeyIndex(key);
        if (keyIndex > -1)
            return ByamlHashIter(mRootNode).getDataByKey(out, keyIndex);
    }
    return false;
}

NON_MATCHING // out is set before return storage, instead of after
bool ByamlIter::tryGetBoolByKey(bool* out, const char* key) const
{
    ByamlData data;

    if (getByamlDataByKey(&data, key))
        return tryConvertBool(out, &data);
    return false;
}
NON_MATCHING // "
bool ByamlIter::tryGetIntByKey(int* out, const char* key) const
{
    ByamlData data;

    if (getByamlDataByKey(&data, key))
        return tryConvertInt(out, &data);
    return false;
}
NON_MATCHING // "
bool ByamlIter::tryGetFloatByKey(float* out, const char* key) const
{
    ByamlData data;

    if (getByamlDataByKey(&data, key))
        return tryConvertFloat(out, &data);
    return false;
}

#pragma inline
bool ByamlIter::tryConvertBool(bool* out, const ByamlData* data) const
{
    if (data->getType() == ByamlDataType_Int || data->getType() == ByamlDataType_Bool) {
        *out = data->getIntValue();
        return true;
    }
    return false;
}

#pragma inline
bool ByamlIter::tryConvertInt(int* out, const ByamlData* data) const
{
    if (data->getType() == ByamlDataType_Int) {
        *out = data->getIntValue();
        return true;
    }
    return false;
}

#pragma inline
bool ByamlIter::tryConvertFloat(float* out, const ByamlData* data) const
{
    if (data->getType() == ByamlDataType_Float) {
        *out = data->getFloatValue();
        return true;
    }
    return false;
}

} // namespace al
