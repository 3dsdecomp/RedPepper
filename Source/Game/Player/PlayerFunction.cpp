#include "Game/Player/PlayerFunction.h"
#include "Game/System/Application.h"

namespace rp {

#pragma no_inline
NON_MATCHING // linker shenanigans
PlayerActor* getPlayerActor()
{
    return Application::instance()->mPlayerActor;
}

const sead::Vector3f& getPlayerTrans()
{
    return al::getTrans(getPlayerActor());
}

} // namespace rp
