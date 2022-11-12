#pragma once

#include "al/Camera/Camera.h"
#include "al/Factory/Factory.h"

namespace al {

typedef CreateFuncPtr<Camera>::Type CreateCameraFuncPtr;
typedef NameToCreator<CreateCameraFuncPtr> NameToCameraCreator;

} // namespace al
