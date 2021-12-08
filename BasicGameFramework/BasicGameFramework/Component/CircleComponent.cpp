#include "CircleComponent.h"

void CircleComponent::Render(HDC hdc)
{
	POINT newPos = calcNewPos();

	Ellipse(hdc, newPos.x, newPos.y, newPos.x + _size.Width, newPos.y + _size.Height);
}
