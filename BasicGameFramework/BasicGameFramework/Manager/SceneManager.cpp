#include "../stdafx.h"

#include "../Scene/TempScene.h"
#include "../Scene/TitleScene.h"

#include "SceneManager.h"

SceneManager::~SceneManager() noexcept
{
	_currentScene = nullptr;
	_nextScene = nullptr;

	for (auto& elem : _scenes)
	{
		delete elem.second;
	}
	_scenes.clear();
}

void SceneManager::Init()
{
	_scenes[L"Title"] = new TitleScene();
	_scenes[L"Temp"] = new TempScene();

	_currentScene = _scenes[L"Title"];
	_currentScene->Init();
}

void SceneManager::Update()
{
	_currentScene->Update();
}

void SceneManager::PhysicsUpdate()
{
	_currentScene->PhysicsUpdate();
}

void SceneManager::Render(HDC hdc)
{
	_currentScene->Render(hdc);
}

void SceneManager::Release()
{
	_currentScene->Release();
}

bool SceneManager::IsSetNextScene() const noexcept
{
	return _nextScene != nullptr;
}

void SceneManager::SetNextScene(const wstring& name)
{
	ASSERT_CRASH(_nextScene == nullptr);
	ASSERT_CRASH(_scenes.end() != _scenes.find(name));

	_nextScene = _scenes[name];
}

void SceneManager::ChangeScene()
{
	if (_nextScene)
	{
		_currentScene->Release();

		_currentScene = _nextScene;
		_currentScene->Init();

		_nextScene = nullptr;
	}
}