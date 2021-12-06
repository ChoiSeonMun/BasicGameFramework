#pragma once

#include <Windows.h>
#include <vector>
#include <string>

#include "../IBehaviour.h"

class Scene;
class Layer;
class Component;

class GameObject abstract : IBehaviour
{
public:
	GameObject(const Scene* scene, const Layer* layer, const wstring& tag);
	virtual ~GameObject() noexcept;

	virtual void	Init() override;
	virtual void	Update() override;
	virtual void	PhysicsUpdate() override;
	virtual void	Render(HDC hdc) override;
	virtual void	Release() override;

	void			AddComponent(Component* component);
	void			RemoveComponent(Component* component);

	void			SetTag(const wstring& tag);
	void			SetPosition(POINT pos);
	void			SetX(INT32 x);
	void			SetY(INT32 y);

	wstring			GetTag() const noexcept;
	POINT			GetPosition() const noexcept;
	INT32			GetX() const noexcept;
	INT32			GetY() const noexcept;
	const Scene*	GetScene() const noexcept;
	const Layer*	GetLayer() const noexcept;
private:
	POINT						_position = {};
	wstring						_tag = L"";
	const Layer*				_layer = nullptr;
	const Scene*				_scene = nullptr;
	vector<Component*>			_components;
};