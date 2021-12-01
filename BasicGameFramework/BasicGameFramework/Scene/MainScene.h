#pragma once

#include "Scene.h"

class MainScene :
    public Scene
{
public:
    virtual void Update() override;

    virtual void Render(HDC hdc) override;

private:
    vector<class GameObject*>   _objects;
};

