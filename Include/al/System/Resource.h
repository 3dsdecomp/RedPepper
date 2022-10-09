#pragma once

#include "sead/prim/seadSafeString.h"

namespace al {

class Resource {
public:
    void* getByml(const sead::SafeString& name);
    void* getPa(const sead::SafeString& name);
};

} // namespace al
