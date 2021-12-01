#pragma once

#include "../Util/Type.h"

class GameObject;

class Component abstract
{
public:
	Component(GameObject* owner, INT32 order = 100) noexcept;
	virtual ~Component() noexcept;

	INT32				GetOrder() const noexcept;

	virtual void		Update();

	bool				operator<(const Component& other) const noexcept;
protected:
	GameObject*			_owner = nullptr;

private:
	INT32				_order = 100;
};