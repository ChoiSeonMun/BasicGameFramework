#include "Player.h"
#include "../Component/RectComponent.h"
#include "../Component/CircleComponent.h"

void Player::Init()
{
	//RectComponent* rect = new RectComponent(this);
	//rect->SetSize(100, 100);
	CircleComponent* circle = new CircleComponent(this);
	circle->SetSize(200, 100);
}
