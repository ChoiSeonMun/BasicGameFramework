#pragma once

#include "DrawComponent.h"

class RectComponent : public DrawComponent
{
public:
	using DrawComponent::DrawComponent;
	virtual ~RectComponent() noexcept;

	virtual void Render(HDC hdc) override;

	void		SetBrush(COLORREF color);
	void		SetPen(COLORREF color, int width = 1, int style = PS_SOLID);
private:
	HBRUSH		_brush = {};
	HPEN		_pen = {};
};