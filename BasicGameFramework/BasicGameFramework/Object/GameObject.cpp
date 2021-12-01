#include "../stdafx.h"
#include "../Component/Component.h"
#include "../Component/DrawComponent.h"

#include "GameObject.h"

GameObject::GameObject(INT32 zOrder) noexcept
	: GameObject()
{
	_zOrder = zOrder;
}

GameObject::~GameObject() noexcept
{
	for (Component* comp : _components)
	{
		delete comp;
	}
	_components.clear();

	for (DrawComponent* comp : _drawComponents)
	{
		delete comp;
	}
	_drawComponents.clear();
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
	for (DrawComponent* comp : _drawComponents)
	{
		comp->Render(hdc);
	}
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
	auto iter = find(_components.begin(), _components.end(), component);

	if (iter == _components.end())
	{
		return;
	}

	delete *iter;

	_components.erase(iter);
}

void GameObject::AddDrawComponent(DrawComponent* drawComponent)
{
	_drawComponents.push_back(drawComponent);

	sort(_drawComponents.begin(), _drawComponents.end());
}

void GameObject::RemoveDrawComponent(DrawComponent* drawComponent)
{
	auto iter = find(_components.begin(), _components.end(), drawComponent);

	if (iter == _components.end())
	{
		return;
	}

	delete *iter;

	_components.erase(iter);
}

void GameObject::SetPosition(POINT pos)
{
	_position = pos;
}

POINT GameObject::GetPosition() const noexcept
{
	return _position;
}

void GameObject::SetZOrder(INT32 zOrder)
{
	_zOrder = zOrder;
}

INT32 GameObject::GetZOrder() const noexcept
{
	return _zOrder;
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
