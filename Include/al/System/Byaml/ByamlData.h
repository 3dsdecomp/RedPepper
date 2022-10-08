#pragma once

#include "types.h"

namespace al {

enum ByamlDataType {
    ByamlDataType_Invalid = 0,
    ByamlDataType_String = 0xA0,
    ByamlDataType_Binary = 0xA1,
    ByamlDataType_Array = 0xC0,
    ByamlDataType_Hash = 0xC1,
    ByamlDataType_StringTable = 0xC2,
    ByamlDataType_BinaryTable = 0xC3,
    ByamlDataType_Bool = 0xD0,
    ByamlDataType_Int = 0xD1,
    ByamlDataType_Float = 0xD2,
    ByamlDataType_Null = 0xFF
};

class ByamlData {
private:
    union Value {
        int vInt;
        float vFloat;
    } mValue;
    ByamlDataType mType;

public:
    ByamlDataType getType() const { return mType; }

    int getIntValue() const { return mValue.vInt; }
    float getFloatValue() const { return mValue.vFloat; }
};

} // namespace al
