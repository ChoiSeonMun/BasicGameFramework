#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	using GameObject::GameObject;

	virtual void Init() override;
};