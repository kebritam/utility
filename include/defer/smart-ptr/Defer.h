#pragma once

#include <memory>

#include "defer/DeferUtil.h"

namespace kbt
{
#define DEFER std::shared_ptr<void> DEFER_VAR_NAME = kbt::DeferOperatorOverloadingHelper { } << [&](...)

    template <class F>
    std::shared_ptr<void> operator<<(DeferOperatorOverloadingHelper, F&& _f)
    {
        return std::shared_ptr<void>(nullptr, std::forward<std::decay_t<F>>(_f));
    }
}