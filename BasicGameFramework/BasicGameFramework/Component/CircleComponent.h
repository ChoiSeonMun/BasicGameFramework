#pragma once

#include "RenderComponent.h"

class CircleComponent : public RenderComponent
{
public:
	using RenderComponent::RenderComponent;
	virtual ~CircleComponent() noexcept = default;

	virtual void Render(HDC hdc) override;
};