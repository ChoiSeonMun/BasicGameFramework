#pragma once

#include <Windows.h>

#include "Component.h"

class RectComponent : public Component
{
public:
	using Component::Component;
	virtual ~RectComponent() noexcept = default;

	virtual void	Render(HDC hdc) override;

	void			SetPen(COLORREF color) noexcept;
	void			SetBrush(COLORREF color) noexcept;
private:
	HPEN			_pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HBRUSH			_brush = CreateSolidBrush(RGB(0, 0, 0));
};