#include "../stdafx.h"
#include "../Component/Component.h"
#include "GameObject.h"

GameObject::~GameObject() noexcept
{
	for (Component* comp : _components)
	{
		delete comp;
	}
	_components.clear();
}

bool GameObject::Init()
{
	return true;
}

void GameObject::Update()
{
	for (Component* comp : _components)
	{
		comp->Update();
	}
}

void GameObject::Render(HDC hdc)
{
}

void GameObject::Release()
{
}

void GameObject::AddComponent(Component* component)
{
	_components.push_back(component);

	sort(_components.begin(), _components.end());
}

void GameObject::RemoveComponent(Component* component)
{
	remove(_components.begin(), _components.end(), component);
}

void GameObject::SetX(INT32 x)
{
	_position.x = x;
}

INT32 GameObject::GetX() const noexcept
{
	return _position.x;
}

void GameObject::SetY(INT32 y)
{
	_position.y = y;
}

INT32 GameObject::GetY() const noexcept
{
	return _position.y;
}
