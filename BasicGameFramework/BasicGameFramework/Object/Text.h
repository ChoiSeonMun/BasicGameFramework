#pragma once

#include "GameObject.h"

class Text : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~Text() noexcept = default;

	virtual void Init() override;
};