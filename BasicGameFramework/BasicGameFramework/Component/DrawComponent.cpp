#include "../stdafx.h"

#include "../Object/GameObject.h"

#include "DrawComponent.h"

DrawComponent::DrawComponent(GameObject* owner, INT32 order, Size size, Pivot pivot) noexcept
	: Component(owner, order)
{
	_size = size;
	_pivot = pivot;
}

void DrawComponent::Update()
{
	Component::Update();
}

void DrawComponent::SetSize(Size size)
{
	_size = size;
}

Size DrawComponent::GetSize() const noexcept
{
	return _size;
}

void DrawComponent::SetPivot(Pivot pivot)
{
	_pivot = pivot;
}

Pivot DrawComponent::GetPivot() const noexcept
{
	return _pivot;
}

POINT DrawComponent::calcNewPos() const noexcept
{
	POINT pos = _owner->GetPosition();
	POINT temp = { _size.Width * _pivot.X, _size.Height * _pivot.Y };

	return POINT{ pos.x - temp.x, pos.y - temp.y };
}
