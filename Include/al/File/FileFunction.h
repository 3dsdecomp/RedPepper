#pragma once

#include <sead/prim/seadSafeString.h>

namespace al {

void loadArchive(const sead::SafeString& archive);

void makeLocalizedArchivePath(sead::BufferedSafeString* out, const sead::SafeString& archive);

} // namespace al
