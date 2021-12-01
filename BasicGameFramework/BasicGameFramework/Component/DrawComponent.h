#pragma once

#include <Windows.h>

#include "Component.h"

class DrawComponent : public Component
{
public:
	DrawComponent(GameObject* owner, INT32 order = 100, Size size = {}, Pivot pivot = Pivot::Center) noexcept;
	virtual ~DrawComponent() noexcept = default;

	virtual void Update() override;
	virtual void Render(HDC hdc) abstract;

	void			SetSize(Size size);
	Size			GetSize() const noexcept;
	void			SetPivot(Pivot pivot);
	Pivot			GetPivot() const noexcept;

protected:
	POINT			calcNewPos() const noexcept;

protected:
	Size			_size = {};
	Pivot			_pivot = Pivot::Center;
};