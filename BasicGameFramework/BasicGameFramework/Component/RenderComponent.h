#pragma once

#include "Component.h"
#include "../Util/Type.h"

class RenderComponent abstract : public Component
{
public:
	using Component::Component;
	virtual ~RenderComponent() noexcept = default;

	void			SetSize(INT32 width, INT32 height) noexcept;
	void			SetSize(Size size) noexcept;
	void			SetPivot(Pivot pivot) noexcept;

	Size			GetSize() const noexcept;
	INT32			GetWidth() const noexcept;
	INT32			GetHeight() const noexcept;
	Pivot			GetPivot() const noexcept;

protected:
	POINT			calcNewPos() const noexcept;

protected:
	Size			_size = {};
	Pivot			_pivot = Pivot::Center;
};