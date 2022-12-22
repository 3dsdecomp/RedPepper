#include <nn/dbg/dbg_Api.h>
#include <nn/svc/svc_Api.h>

namespace nn {
namespace dbg {

    void Break(BreakReason reason)
    {
        nn::svc::Break(reason);
    }

} // namespace dbg
} // namespace nn
