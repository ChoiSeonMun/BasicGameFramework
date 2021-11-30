#pragma once

template <typename T>
class Singleton abstract
{
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singelton&&) = delete;
	virtual ~Singleton() = default;

	static T* GetInstance() noexcept
	{
		static T instance;

		return &instance;
	}

protected:
	Singleton() noexcept = default;
};