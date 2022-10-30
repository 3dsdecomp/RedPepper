#include "Game/System/Application.h"

NON_MATCHING
SEAD_SINGLETON_DISPOSER_IMPL(Application)

Application* al::getApplication()
{
    return Application::instance();
}
