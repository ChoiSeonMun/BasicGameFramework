#pragma once

#include <Windows.h>
#include <vector>

class GameObject;

class Scene abstract
{
public:
	virtual ~Scene() noexcept = default;

	virtual void	Init() abstract;
	virtual void	Update() abstract;
	virtual void	Render(HDC hdc) abstract;
	virtual void	Release() abstract;

	void			AddObject(GameObject* obj);
	void			RemoveObject(GameObject* obj);

private:
	class SortByZOrder
	{
	public:
		bool operator()(GameObject* lhs, GameObject* rhs) const;
	};
private:
	SortByZOrder			_sortByZOrder;
	vector<GameObject*>		_objects;
};