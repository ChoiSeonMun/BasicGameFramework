#include "Obstacle.h"

#include "../Component/RectComponent.h"

void Obstacle::Init()
{
	RectComponent* rect = new RectComponent(this);
	rect->SetPen(RGB(255, 0, 0));
	rect->SetBrush(RGB(128, 128, 128));

	SetSize(100, 100);
}
