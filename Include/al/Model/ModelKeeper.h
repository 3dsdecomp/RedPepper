#pragma once

#include <sead/math/seadMatrix.h>

namespace al {

class ModelKeeper {
public:
};

const sead::Matrix34f* getJointMtxPtr(ModelKeeper* keeper, const char* jointName);

} // namespace al
