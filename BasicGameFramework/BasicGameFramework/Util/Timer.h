#pragma once

#include "Util/Singleton.h"

class Timer : public Singleton<Timer>
{
public:
	Timer() noexcept = default;
	virtual ~Timer() noexcept = default;

	void			SetTimeScale(float timeScale);
	float			GetTimeScale() const noexcept;
	float			GetDeltaTime() const noexcept;

	void			Init();
	void			Update();

public:
	static constexpr float MS_PER_UPDATE = 1000.0f / 60.0f;

private:
	high_resolution_clock::time_point	_prevTime = {};
	float								_deltaTime = 0.0f;
	float								_timeScale = 1.0f;
};

