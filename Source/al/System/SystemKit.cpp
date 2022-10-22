#include "al/System/SystemKit.h"
#include "Game/System/Application.h"

namespace alProjectInterface {

al::SystemKit* getSystemKit()
{
    return Application::instance()->mSystemKit;
}

} // namespace alProjectInterface
