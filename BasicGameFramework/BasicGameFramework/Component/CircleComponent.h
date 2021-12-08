#pragma once

#include "Component.h"

class CircleComponent : public Component
{
public:
	using Component::Component;
	virtual ~CircleComponent() noexcept = default;

	virtual void	Render(HDC hdc) override;
};