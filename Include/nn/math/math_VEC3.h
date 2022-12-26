#pragma once

namespace nn {
namespace math {

    struct VEC3 {
        float x;
        float y;
        float z;
    };

    namespace ARMv6 {

        void VEC3AddAsm(VEC3* out, const VEC3* v1, const VEC3* v2);
        void VEC3SubAsm(VEC3* out, const VEC3* v1, const VEC3* v2);
        void VEC3MulAsm(VEC3* out, const VEC3* v1, const VEC3* v2);
        void VEC3DivAsm(VEC3* out, const VEC3* v1, const VEC3* v2);

        void VEC3AddAsm(VEC3* out, const VEC3* v1, float f);
        void VEC3SubAsm(VEC3* out, const VEC3* v1, float f);
        void VEC3MulAsm(VEC3* out, const VEC3* v1, float f);
        void VEC3DivAsm(VEC3* out, const VEC3* v1, float f);

    } // namespace ARMv6

} // namespace math
} // namespace nn
