#pragma once

#include "GameObject.h"

class Obstacle final : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~Obstacle() noexcept = default;

	virtual void Init() override;
};