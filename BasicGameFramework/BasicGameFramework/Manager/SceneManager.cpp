#include "../stdafx.h"
#include "../Scene/Scene.h"
#include "../Scene/MainScene.h"

#include "SceneManager.h"

SceneManager::~SceneManager() noexcept
{
	_currentScene = nullptr;

	for (auto& elem : _scenes)
	{
		delete elem.second;
	}
	_scenes.clear();
}

void SceneManager::Init()
{
	_scenes["MainScene"] = new MainScene();

	_currentScene = _scenes["MainScene"];
	_currentScene->Init();
}

void SceneManager::Update()
{
	_currentScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	_currentScene->Render(hdc);
}

void SceneManager::ChangeScene(const string& name)
{
	_currentScene->Release();

	ASSERT_CRASH(_scenes.end() == _scenes.find(name));

	_currentScene = _scenes[name];
	_currentScene->Init();
}