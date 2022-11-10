#pragma once

#include "al/Audio/AudioKeeper.h"
#include <sead/prim/seadSafeString.h>

namespace al {

void startSe(IUseAudioKeeper* p, const sead::SafeString& name);
bool tryStartSe(IUseAudioKeeper* p, const sead::SafeString& name, int /* ? */);

} // namespace al
