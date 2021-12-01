#include "../stdafx.h"

#include "Timer.h"

using namespace std;
using namespace std::chrono;

void Timer::SetTimeScale(float timeScale)
{
	_timeScale = timeScale;
}

float Timer::GetTimeScale() const noexcept
{
	return _timeScale;
}

float Timer::GetDeltaTime() const noexcept
{
	return _deltaTime * _timeScale;
}

void Timer::Init()
{
	_prevTime = high_resolution_clock::now();
}

void Timer::Update()
{
	auto current = high_resolution_clock::now();

	duration<float, milli> elapsed = current - _prevTime;

	if (1000.0f / static_cast<float>(_fps) > elapsed.count())
	{
		_isElapsed = false;

		return;
	}

	_deltaTime = elapsed.count();

	_prevTime = current;

	_isElapsed = true;
}

bool Timer::IsElapsed() const noexcept
{
	return _isElapsed;
}
