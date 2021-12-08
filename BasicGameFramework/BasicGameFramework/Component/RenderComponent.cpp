#include "RenderComponent.h"
#include "../Object/GameObject.h"

void RenderComponent::SetSize(INT32 width, INT32 height) noexcept
{
	_size = Size{ width, height };
}

void RenderComponent::SetSize(Size size) noexcept
{
	_size = size;
}

void RenderComponent::SetPivot(Pivot pivot) noexcept
{
	_pivot = pivot;
}

Size RenderComponent::GetSize() const noexcept
{
	return _size;
}

INT32 RenderComponent::GetWidth() const noexcept
{
	return _size.Width;
}

INT32 RenderComponent::GetHeight() const noexcept
{
	return _size.Height;
}

Pivot RenderComponent::GetPivot() const noexcept
{
	return Pivot();
}

POINT RenderComponent::calcNewPos() const noexcept
{
	POINT pos = _owner->GetPosition();
	POINT temp = { _size.Width * _pivot.X, _size.Height * _pivot.Y };

	return POINT{ pos.x - temp.x, pos.y - temp.y };
}
