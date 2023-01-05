#pragma once

#include <sead/math/seadQuat.h>

namespace al {

void rotateQuatXDirDegree(sead::Quatf* out, const sead::Quatf& from, float degrees);
void rotateQuatYDirDegree(sead::Quatf* out, const sead::Quatf& from, float degrees);
void rotateQuatZDirDegree(sead::Quatf* out, const sead::Quatf& from, float degrees);

void calcQuatSide(sead::Vector3f* out, const sead::Quatf& from);

} // namespace al
