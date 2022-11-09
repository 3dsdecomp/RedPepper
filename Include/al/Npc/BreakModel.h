#pragma once

#include "al/LiveActor/LiveActor.h"

namespace al {

class BreakModel : public LiveActor {
    LiveActor* mParent;
    const sead::Matrix34f* mParentBaseMtx;
    const char* mModelArchiveName;
    const char* mBreakActionName;

public:
    BreakModel(LiveActor* parent, const char* name, const char* modelArchiveName, const sead::Matrix34f* parentBaseMtx = nullptr, const char* breakActionName = "Break");

    virtual void init(const ActorInitInfo& info);
    virtual void appear();

    void exeWait();
    void exeBreak();
};

} // namespace al
