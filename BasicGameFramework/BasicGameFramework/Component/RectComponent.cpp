#include "RectComponent.h"
#include "../Object/GameObject.h"

void RectComponent::Render(HDC hdc)
{
	POINT newPos = _owner->GetRenderPos();
	Size size = _owner->GetSize();

	HPEN oldPen = static_cast<HPEN>(SelectObject(hdc, _pen));
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(hdc, _brush));

	Rectangle(hdc, newPos.x, newPos.y, newPos.x + size.Width, newPos.y + size.Height);

	SelectObject(hdc, oldPen);
	SelectObject(hdc, oldBrush);
}

void RectComponent::SetPen(COLORREF color) noexcept
{
	_pen = CreatePen(PS_SOLID, 1, color);
}

void RectComponent::SetBrush(COLORREF color) noexcept
{
	_brush = CreateSolidBrush(color);
}
