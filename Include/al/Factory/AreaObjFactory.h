#pragma once

#include "al/AreaObj/AreaObj.h"
#include "al/Factory/Factory.h"

namespace al {

typedef CreateFuncPtr<AreaObj>::Type CreateAreaObjFuncPtr;
typedef NameToCreator<CreateAreaObjFuncPtr> NameToAreaObjCreator;

} // namespace al
