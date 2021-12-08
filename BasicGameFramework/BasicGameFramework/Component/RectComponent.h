#pragma once

#include "RenderComponent.h"

class RectComponent : public RenderComponent
{
public:
	using RenderComponent::RenderComponent;
	virtual ~RectComponent() noexcept = default;

	virtual void Render(HDC hdc) override;
};