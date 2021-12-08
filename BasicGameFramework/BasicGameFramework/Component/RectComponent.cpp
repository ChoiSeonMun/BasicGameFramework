#include "RectComponent.h"
#include "../Object/GameObject.h"

void RectComponent::Render(HDC hdc)
{
	POINT newPos = calcNewPos();
	
	Rectangle(hdc, newPos.x, newPos.y, newPos.x + _size.Width, newPos.y + _size.Height);
}