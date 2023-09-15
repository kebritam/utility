#pragma once

#include <memory>

#include "defer/DeferUtil.h"

namespace kbt
{
#define DEFER(func) std::shared_ptr<void> DEFER_VAR_NAME(nullptr, [&](...) {func})
}