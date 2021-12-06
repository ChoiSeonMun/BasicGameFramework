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
	GameObject(Scene* scene, Layer* layer, const wstring& tag);
	virtual ~GameObject() noexcept;

	virtual void	Init() override;
	virtual void	Update() override;
	virtual void	PhysicsUpdate() override;
	virtual void	Render(HDC hdc) override;
	virtual void	Release() override;

	void			AddComponent(Component* component);
	void			RemoveComponent(Component* component);
	vector<Component*>& GetComponents() noexcept;
	template <typename T>
	T*				GetComponent()
	{
		static_assert(is_base_of_v<Component, T>, "T for GetComponent() must be component");

		for (Component* comp : _components)
		{
			if (dynamic_cast<T*>(comp))
			{
				return comp;
			}
		}
	}

	void			SetTag(const wstring& tag);
	void			SetPosition(POINT pos);
	void			SetX(INT32 x);
	void			SetY(INT32 y);

	wstring			GetTag() const noexcept;
	POINT			GetPosition() const noexcept;
	INT32			GetX() const noexcept;
	INT32			GetY() const noexcept;
	Scene*			GetScene() noexcept;
	Layer*			GetLayer() noexcept;
private:
	POINT						_position = {};
	wstring						_tag = L"";
	Layer*				_layer = nullptr;
	Scene*				_scene = nullptr;
	vector<Component*>			_components;
};