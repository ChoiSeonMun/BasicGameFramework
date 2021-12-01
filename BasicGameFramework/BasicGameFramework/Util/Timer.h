#pragma once

#include "Singleton.h"

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

	bool			IsElapsed() const noexcept;
private:
	high_resolution_clock::time_point	_prevTime = {};
	float								_deltaTime = 0.0f;
	float								_timeScale = 1.0f;
	INT32								_fps = 60;
	bool								_isElapsed = false;
};

