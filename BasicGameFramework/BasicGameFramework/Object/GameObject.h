#pragma once

#include <Windows.h>
#include <vector>
#include <string>

#include "../Util/Type.h"
#include "../IBehaviour.h"

class Scene;
class Layer;
class Component;

class GameObject abstract : IBehaviour
{
public:
	GameObject(Scene* scene, Layer* layer, const std::wstring& tag);
	virtual ~GameObject() noexcept;

	virtual void	Init() override;
	virtual void	Update() override;
	virtual void	PhysicsUpdate() override;
	virtual void	Render(HDC hdc) override;
	virtual void	Release() override;

	void						AddComponent(Component* component);
	void						RemoveComponent(Component* component);
	std::vector<Component*>&	GetComponents() noexcept;
	template <typename T>
	T*	GetComponent()
	{
		static_assert(std::is_base_of_v<Component, T>, "T for GetComponent() must be component");

		for (Component* comp : _components)
		{
			if (dynamic_cast<T*>(comp))
			{
				return static_cast<T*>(comp);
			}
		}
	}

	POINT			GetRenderPos() const noexcept;

	void			SetTag(const std::wstring& tag) noexcept;
	void			SetPosition(POINT pos) noexcept;
	void			SetPosition(LONG x, LONG y) noexcept;
	void			SetX(LONG x) noexcept;
	void			SetY(LONG y) noexcept;
	void			SetSize(INT32 width, INT32 height) noexcept;
	void			SetSize(Size size) noexcept;
	void			SetPivot(Pivot pivot) noexcept;

	std::wstring	GetTag() const noexcept;
	POINT			GetPosition() const noexcept;
	LONG			GetX() const noexcept;
	LONG			GetY() const noexcept;
	Size			GetSize() const noexcept;
	INT32			GetWidth() const noexcept;
	INT32			GetHeight() const noexcept;
	Pivot			GetPivot() const noexcept;
	Scene*			GetScene() noexcept;
	Layer*			GetLayer() noexcept;
private:
	POINT						_position = {};
	Size						_size = {};
	Pivot						_pivot = Pivot::Bottom;
	Layer*						_layer = nullptr;
	Scene*						_scene = nullptr;
	std::wstring				_tag = L"";
	std::vector<Component*>		_components;
};