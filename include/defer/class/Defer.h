#pragma once

#include "defer/DeferUtil.h"

namespace kbt
{
#define DEFER(func) auto DEFER_VAR_NAME = kbt::DeferDeduceHelper([&] { func })

    template <class F>
    class DeferAction
    {
        F m_func;

    public:
    	explicit DeferAction(F&& _f) noexcept
    		: m_func(std::move(_f))
        {
        }

        ~DeferAction() noexcept
        {
    		m_func();
        }

        DeferAction(DeferAction&& _other) = delete;
        void operator=(DeferAction&&) = delete;
        DeferAction(const DeferAction&) = delete;
        void operator=(const DeferAction&) = delete;
    };

    template <class F>
    [[nodiscard]] auto DeferDeduceHelper(F&& _f) noexcept
    {
        return DeferAction<F>{std::forward<F>(_f)};
    }
}
