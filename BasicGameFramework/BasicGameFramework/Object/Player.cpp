#include "Player.h"

#include "../Component/RectComponent.h"
#include "../Component/CircleComponent.h"

#include "../Component/Player/PlayerMovement.h"

void Player::Init()
{
	//RectComponent* rect = new RectComponent(this);
	//rect->SetSize(100, 100);
	PlayerMovement* movement = new PlayerMovement(this, 1);
	movement->SetSpeed(1.0f);

	CircleComponent* circle = new CircleComponent(this);
	
	SetSize(200, 100);
}
