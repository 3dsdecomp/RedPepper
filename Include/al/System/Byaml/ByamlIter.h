#pragma once

#include "al/System/Byaml/ByamlContainerHeader.h"
#include "al/System/Byaml/ByamlData.h"
#include "al/System/Byaml/ByamlHeader.h"

namespace al {

class ByamlIter {
    union {
        const u8* mData;
        const ByamlHeader* mHeader;
    };
    union {
        const u8* mRootNode;
        const ByamlContainerHeader* mContainerHeader;
    };

public:
    ByamlIter();
    ByamlIter(const u8* data);
    ByamlIter(const u8* data, const u8* rootNode);

    bool isEqualData(const ByamlIter& other) const;

    bool isValid() const;
    bool isTypeArray() const;
    bool isTypeHash() const;
    bool isTypeContainer() const;

    int getSize() const;

    bool isExistKey(const char* key) const;
    int getKeyIndex(const char* key) const;
    bool getKeyName(const char** out, int index) const;

    bool getByamlDataByIndex(ByamlData* out, int index) const;
    bool getByamlDataByKey(ByamlData* out, const char* key) const;
    bool getByamlDataByKeyIndex(ByamlData* out, int index) const;
    bool getByamlDataAndKeyName(ByamlData* out, const char** key, int index) const;

    bool tryGetStringByIndex(const char** out, int index) const;
    bool tryGetStringByKey(const char** out, const char* key) const;
    bool tryGetBinaryByIndex(const u8** out, int* size, int index) const;
    bool tryGetBinaryByKey(const u8** out, int* size, const char* key) const;
    ByamlIter getIterByIndex(int index) const;
    bool tryGetIterByIndex(ByamlIter* out, int index) const;
    ByamlIter getIterByKey(const char* key) const;
    bool tryGetIterByKey(ByamlIter* out, const char* key) const;
    bool tryGetIterAndKeyNameByIndex(ByamlIter* out, const char** key, int index) const;
    bool tryGetBoolByIndex(bool* out, int index) const;
    bool tryGetBoolByKey(bool* out, const char* key) const;
    bool tryGetIntByIndex(int* out, int index) const;
    bool tryGetIntByKey(int* out, const char* key) const;
    bool tryGetFloatByIndex(float* out, int index) const;
    bool tryGetFloatByKey(float* out, const char* key) const;

    bool tryConvertString(const char** out, const ByamlData* data) const;
    bool tryConvertBinary(const u8** out, int* size, const ByamlData* data) const;
    bool tryConvertIter(ByamlIter* iter, const ByamlData* data) const;
    bool tryConvertBool(bool* out, const ByamlData* data) const;
    bool tryConvertInt(int* out, const ByamlData* data) const;
    bool tryConvertFloat(float* out, const ByamlData* data) const;

    const ByamlHeader* getHeader() const { return mHeader; }
};

} // namespace al
