#include "Game/Player/PlayerFunction.h"
#include "Game/System/Application.h"

namespace rp {

#ifdef NON_MATCHING // linker shenanigans
#pragma no_inline
PlayerActor* getPlayerActor()
{
    return Application::instance()->mPlayerActor;
}
#endif

const sead::Vector3f& getPlayerTrans()
{
    return al::getTrans(getPlayerActor());
}

} // namespace rp
