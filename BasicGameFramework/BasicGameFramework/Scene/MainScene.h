#pragma once

#include "Scene.h"

class MainScene :
    public Scene
{
public:
    virtual ~MainScene() noexcept = default;

    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
};

