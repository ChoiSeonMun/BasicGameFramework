#include "CircleComponent.h"
#include "../Object/GameObject.h"

void CircleComponent::Render(HDC hdc)
{
	POINT pos = _owner->GetRenderPos();
	Size size = _owner->GetSize();

	Ellipse(hdc, pos.x, pos.y, pos.x + size.Width, pos.y + size.Height);
}
