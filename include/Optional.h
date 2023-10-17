#pragma once

namespace kbt
{
	class OptionalAccessViolation : public std::runtime_error
	{
	public:
		OptionalAccessViolation()
			: std::runtime_error("The optional does not have any value.")
		{
		}
	};

	template<typename T>
	class Optional
	{
		bool m_hasValue = false;
		alignas(T) char m_value[sizeof(T)];

		template<typename... Args>
		void construct(Args&&... _args)
		{
			new (m_value) T(std::forward<Args>(_args)...);
		}

		void destruct() noexcept
		{
			data()->T::~T();
		}

		const T* data() const
		{
			return reinterpret_cast<const T*>(m_value);
		}
		T* data()
		{
			return reinterpret_cast<T*>(m_value);
		}

	public:
		Optional() noexcept = default;

		explicit Optional(const T& _element)
		{
			construct(_element);
			m_hasValue = true;
		}
		Optional& operator=(const T& _element)
		{
			if (m_hasValue)
			{
				*data() = _element;
			}
			else
			{
				construct(_element);
				m_hasValue = true;
			}
			return *this;
		}

		explicit Optional(T&& _element)
		{
			construct(std::move(_element));
			m_hasValue = true;
		}
		Optional& operator=(T&& _element)
		{
			if (m_hasValue)
			{
				*data() = std::move(_element);
			}
			else
			{
				construct(std::move(_element));
				m_hasValue = true;
			}
			return *this;
		}

		~Optional()
		{
			if (m_hasValue)
			{
				destruct();
			}
		}

		Optional(const Optional& _other)
			: m_hasValue(_other.m_hasValue)
		{
			if (m_hasValue)
			{
				construct(*_other.data());
			}
		}
		Optional& operator=(const Optional& _other)
		{
			if (this != &_other)
			{
				if (_other.m_hasValue)
				{
					Emplace(*_other.data());
				}
				else
				{
					Reset();
				}
			}
			return *this;
		}

		Optional(Optional&& _other) noexcept
			: m_hasValue(_other.m_hasValue)
		{
			if (m_hasValue)
			{
				construct(std::move(*_other.data()));
			}
		}
		Optional& operator=(Optional&& _other) noexcept
		{
			if (this != &_other)
			{
				if (_other.m_hasValue)
				{
					Emplace(std::move(*_other.data()));
				}
				else
				{
					Reset();
				}
			}
			return *this;
		}

		explicit operator bool() const
		{
			return m_hasValue;
		}

		bool IsValid() const
		{
			return m_hasValue;
		}

		const T& Value() const
		{
			if (!m_hasValue)
			{
				throw OptionalAccessViolation();
			}
			return *data();
		}
		T& Value()
		{
			if (!m_hasValue)
			{
				throw OptionalAccessViolation();
			}
			return *data();
		}

		const T& operator*() const
		{
			return Value();
		}
		T& operator*()
		{
			return Value();
		}

		const T* operator->() const
		{
			return &Value();
		}
		T* operator->()
		{
			return &Value();
		}

		void Reset()
		{
			if (m_hasValue)
			{
				destruct();
				m_hasValue = false;
			}
		}

		const T& ValueOr(const T& _defaultValue) const
		{
			if (!m_hasValue)
				return _defaultValue;
			return *data();
		}

		T& ValueOr(const T& _defaultValue)
		{
			if (!m_hasValue)
				return _defaultValue;
			return *data();
		}

		template<typename... Args>
		void Emplace(Args&&... _args)
		{
			Reset();
			construct(std::forward<Args>(_args)...);
			m_hasValue = true;
		}
	};
}