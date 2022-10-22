#include "al/File/FileFunction.h"
#include "al/Message/MessageFunction.h"

namespace al {

void makeLocalizedArchivePath(sead::BufferedSafeString* out, const sead::SafeString& archive)
{
    out->format("LocalizedData/%s/%s", al::getLanguage(), archive.cstr());
}

} // namespace al
