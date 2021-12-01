#include "../stdafx.h"
#include "../Object/GameObject.h"

#include "Scene.h"

void Scene::Init()
{
	for (GameObject* obj : _objects)
	{
		obj->Init();
	}
}

void Scene::Update()
{
	for (GameObject* obj : _objects)
	{
		obj->Update();
	}
}

void Scene::Render(HDC hdc)
{
	for (GameObject* obj : _objects)
	{
		obj->Render(hdc);
	}
}

void Scene::Release()
{
	for (GameObject* obj : _objects)
	{
		obj->Release();
	}
}
