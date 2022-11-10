#pragma once

#include <sead/prim/seadSafeString.h>

namespace al {

bool isExistArchive(const sead::SafeString& archive);
void loadArchive(const sead::SafeString& archive);

void makeLocalizedArchivePath(sead::BufferedSafeString* out, const sead::SafeString& archive);

} // namespace al
