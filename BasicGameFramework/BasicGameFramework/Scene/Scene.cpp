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

void Scene::AddObject(GameObject* obj)
{
	_objects.push_back(obj);

	sort(_objects.begin(), _objects.end(), _sortByZOrder);
}

void Scene::RemoveObject(GameObject* obj)
{
	auto iter = find(_objects.begin(), _objects.end(), obj);

	if (iter == _objects.end())
	{
		return;
	}

	delete *iter;

	_objects.erase(iter);
}

bool Scene::SortByZOrder::operator()(GameObject* lhs, GameObject* rhs) const
{
	return lhs->GetZOrder() < rhs->GetZOrder();}
