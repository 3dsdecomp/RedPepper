#include <nn/srv/detail/srv_Service.h>
#include <nn/srv/srv_Api.h>

namespace nn {
namespace srv {

    namespace {

        static int s_InitializeCount = 0;

    } // namespace

    NON_MATCHING
    Result GetServiceHandle(Handle* out, const char* service, s32 r2, u32 r3)
    {
        if (s_InitializeCount > 0)
            return Result(Result::Level_Permanent, Result::Summary_InvalidState, Result::ModuleType_SRV, Result::Description_NotInitialized);
        if (8 < r2)
            return Result(Result::Level_Permanent, Result::Summary_WrongArgument, Result::ModuleType_SRV, 5);

        return detail::Service::GetServiceHandle(out, service, r2, r3);
    }

} // namespace srv
} // namespace nn
