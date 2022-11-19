#pragma once

#include <sead/prim/seadSafeString.h>

namespace al {

class Resource {
public:
    const u8* getByml(const sead::SafeString& name) const;
    u8* getPa(const sead::SafeString& name) const;
};

Resource* findOrCreateResource(const sead::SafeString& archive);

} // namespace al
