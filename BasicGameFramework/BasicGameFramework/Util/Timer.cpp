#include "../stdafx.h"

#include "Timer.h"

using namespace std;
using namespace std::chrono;

high_resolution_clock::time_point Timer::_prevTime = {};
float Timer::_deltaTime = 0.0f;
float Timer::_timeScale = 1.0f;

void Timer::SetTimeScale(float timeScale)
{
	_timeScale = timeScale;
}

float Timer::GetTimeScale() noexcept
{
	return _timeScale;
}

float Timer::GetDeltaTime() noexcept
{
	return _deltaTime * _timeScale;
}

void Timer::Init() noexcept
{
	_prevTime = high_resolution_clock::now();
}

bool Timer::CanUpdate() noexcept
{
	auto current = high_resolution_clock::now();

	duration<float, milli> elapsed = current - _prevTime;

	if (MS_PER_UPDATE > elapsed.count())
	{
		return false;
	}

	_deltaTime = elapsed.count();

	_prevTime = current;

	return true;
}