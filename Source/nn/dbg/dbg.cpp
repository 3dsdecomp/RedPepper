#include <nn/dbg/dbg.h>
#include <nn/svc/svc.h>

namespace nn {
namespace dbg {

    void Break(BreakReason reason)
    {
        nn::svc::Break(reason);
    }

} // namespace dbg
} // namespace nn
