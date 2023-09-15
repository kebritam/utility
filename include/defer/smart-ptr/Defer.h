#pragma once

#include <memory>

namespace kbt
{
#define CONCAT_HELPER(s1,s2) s1##s2
#define CONCAT(s1,s2) CONCAT_HELPER(s1,s2)
#define DEFER_VAR_NAME CONCAT(deferVar, __COUNTER__)

#define DEFER(func) std::shared_ptr<void> DEFER_VAR_NAME(nullptr, [&](...) {func})
}