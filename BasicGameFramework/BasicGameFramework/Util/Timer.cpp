#include "stdafx.h"
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

	duration<double, milli> elapsed = current - _prevTime;

	_deltaTime = elapsed.count();

	_prevTime = current;
}
