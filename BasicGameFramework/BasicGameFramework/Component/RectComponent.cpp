#include "../stdafx.h"

#include "RectComponent.h"

RectComponent::~RectComponent() noexcept
{
	DeleteObject(_brush);
	DeleteObject(_pen);
}

void RectComponent::Render(HDC hdc)
{
	POINT newPos = calcNewPos();
	
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(hdc, _brush));
	HPEN oldPen = static_cast<HPEN>(SelectObject(hdc, _pen));
	Rectangle(hdc, newPos.x, newPos.x, newPos.x + _size.Width, newPos.y + _size.Height);

	SelectObject(hdc, oldBrush);
	SelectObject(hdc, oldPen);
}

void RectComponent::SetBrush(COLORREF color)
{
	_brush = CreateSolidBrush(color);
}

void RectComponent::SetPen(COLORREF color, int width, int style)
{
	_pen = CreatePen(style, width, color);
}
