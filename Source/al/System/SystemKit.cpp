#include "al/System/SystemKit.h"
#include "Game/System/Application.h"

namespace alProjectInterface {

al::SystemKit* getSystemKit()
{
    return al::getApplication()->mSystemKit;
}

} // namespace alProjectInterface
