#pragma once

#include <variant>

namespace kbt
{
	template<typename Left, typename Right>
	class Either
	{
		std::variant<Left, Right> m_variant;
		bool m_isLeft;

	public:

		explicit Either(const Left& _left)
			: m_variant(_left)
			, m_isLeft(true)
		{
		}

		explicit Either(const Right& _right)
			: m_variant(_right)
			, m_isLeft(false)
		{
		}

		template <typename LF, typename RF>
		void Match(LF&& _lf, RF&& _rf)
		{
			m_isLeft ?
				_lf(std::get<Left>(m_variant)) :
				_rf(std::get<Right>(m_variant));
		}

		template <typename T, typename LF, typename RF>
		T Match(LF&& _lf, RF&& _rf)
		{
			return m_isLeft ?
				_lf(std::get<Left>(m_variant)) :
				_rf(std::get<Right>(m_variant));
		}

	};
}