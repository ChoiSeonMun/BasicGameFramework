#pragma once

#include "GameObject.h"

class Obstacle : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~Obstacle() noexcept = default;

	virtual void Init() override;
};