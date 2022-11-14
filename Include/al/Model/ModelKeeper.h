#pragma once

#include "al/Model/alModelCtr.h"
#include <sead/math/seadMatrix.h>

namespace al {

class ModelKeeper {
    alModelCtr* mModel;

public:
    alModelCtr* getModel() const { return mModel; }
};

const sead::Matrix34f* getJointMtxPtr(ModelKeeper* keeper, const char* jointName);

} // namespace al
