#include "PlayerMovement.h"
#include "../CircleComponent.h"

#include "../../Object/GameObject.h"
#include "../../Util/Input.h"
#include "../../Util/Timer.h"

void PlayerMovement::Update()
{
	POINT pos = _owner->GetPosition();

	if (Input::GetButton('W'))
	{
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
	}

	if (Input::GetButton('S'))
	{
		pos.y += static_cast<LONG>(_speed * Timer::GetDeltaTime());
	}

	if (Input::GetButton('A'))
	{
		pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
	}

	if (Input::GetButton('D'))
	{
		pos.x += static_cast<LONG>(_speed * Timer::GetDeltaTime());
	}

	_owner->SetPosition(pos);
}

void PlayerMovement::SetSpeed(float speed) noexcept
{
	_speed = speed;
}

float PlayerMovement::GetSpeed() const noexcept
{
	return _speed;
}
