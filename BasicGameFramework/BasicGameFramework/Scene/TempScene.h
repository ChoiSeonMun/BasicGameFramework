#pragma once

#include "Scene.h"

class TempScene final : public Scene
{
public:
	using Scene::Scene;

	virtual ~TempScene() noexcept = default;

	virtual void Init() override;
};