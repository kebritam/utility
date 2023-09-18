#pragma once

#include <utility>

#include "defer/DeferUtil.h"

namespace kbt
{
#define DEFER auto DEFER_VAR_NAME = kbt::DeferOperatorOverloadingHelper{ } << [&]

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

        DeferAction(DeferAction&&) = delete;
        void operator=(DeferAction&&) = delete;
        DeferAction(const DeferAction&) = delete;
        void operator=(const DeferAction&) = delete;
    };

    template <class F>
    DeferAction<F> operator<<(DeferOperatorOverloadingHelper, F&& _f)
    {
        return DeferAction<F>(std::forward<std::decay_t<F>>(_f));
    }
}
