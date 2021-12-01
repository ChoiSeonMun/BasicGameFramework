#pragma once

#include <Windows.h>

class Scene;

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager() noexcept = default;
	~SceneManager() noexcept;

	void		Init();
	void		Update();
	void		Render(HDC hdc);
	void		ChangeScene(const string& name);
private:
	Scene*							_currentScene = nullptr;
	unordered_map<string, Scene*>	_scenes;
};