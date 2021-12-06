#include "../stdafx.h"
#include "../Component/Component.h"

#include "GameObject.h"

GameObject::GameObject(const Scene* scene, const Layer* layer, const wstring& tag)
	:
	_scene(scene),
	_layer(layer),
	_tag{ tag }
{
}

GameObject::~GameObject() noexcept
{
	for (auto& comp : _components)
	{
		delete comp;
		comp = nullptr;
	}
	_components.clear();
	_layer = nullptr;
	_scene = nullptr;
}

void GameObject::Init()
{
	for (Component* comp : _components)
	{
		comp->Init();
	}
}

void GameObject::Update()
{
	for (Component* comp : _components)
	{
		comp->Update();
	}
}

void GameObject::PhysicsUpdate()
{
	for (Component* comp : _components)
	{
		comp->PhysicsUpdate();
	}
}

void GameObject::Render(HDC hdc)
{
	for (Component* comp : _components)
	{
		comp->Render(hdc);
	}
}

void GameObject::Release()
{
	for (Component* comp : _components)
	{
		comp->Release();
	}
}

void GameObject::AddComponent(Component* component)
{
	_components.push_back(component);

	sort(_components.begin(), _components.end(),
		[](const Component* lhs, const Component* rhs)
		{
			return lhs->GetOrder() < rhs->GetOrder();
		});
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

void GameObject::SetTag(const wstring& tag)
{
	_tag = tag;
}

void GameObject::SetPosition(POINT pos)
{
	_position = pos;
}

wstring GameObject::GetTag() const noexcept
{
	return _tag;
}

POINT GameObject::GetPosition() const noexcept
{
	return _position;
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

const Scene* GameObject::GetScene() const noexcept
{
	return _scene;
}

const Layer* GameObject::GetLayer() const noexcept
{
	return _layer;
}
