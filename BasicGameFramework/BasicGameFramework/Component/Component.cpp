#include "../stdafx.h"
#include "../Object/GameObject.h"

#include "Component.h"

Component::Component(GameObject* owner, INT32 order) noexcept
	: _owner{ owner }, _order{ order }
{
	_owner->AddComponent(this);
}

Component::~Component() noexcept
{
	_owner->RemoveComponent(this);
	_owner = nullptr;
}

INT32 Component::GetOrder() const noexcept
{
	return _order;
}

void Component::Init()
{
}

void Component::Update()
{
}

void Component::PhysicsUpdate()
{
}

void Component::Render(HDC hdc)
{
}

void Component::Release()
{
}