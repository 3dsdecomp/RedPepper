#include "al/File/FileFunction.h"
#include "al/Message/MessageFunction.h"
#include "al/System/SystemKit.h"
#include "al/Util/StringUtil.h"

namespace al {

void loadArchive(const sead::SafeString& archive)
{
    alProjectInterface::getSystemKit()->getFileLoader()->loadArchive(StringTmp<256>("%s.szs", archive.cstr()), nullptr);
}

void makeLocalizedArchivePath(sead::BufferedSafeString* out, const sead::SafeString& archive)
{
    out->format("LocalizedData/%s/%s", al::getLanguage(), archive.cstr());
}

void makeStageDataArchivePath(sead::BufferedSafeString* out, const char* stageName, int scenario, const char* type)
{
    out->format("StageData/%s%s%d", stageName, type, scenario);
}

} // namespace al
