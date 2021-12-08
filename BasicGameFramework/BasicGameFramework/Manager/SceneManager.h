#pragma once

#include <Windows.h>
#include <string>
#include <unordered_map>

#include "../Util/Singleton.h"
#include "../IBehaviour.h"

class Scene;

class SceneManager : public Singleton<SceneManager>, IBehaviour
{
public:
	SceneManager() noexcept = default;
	~SceneManager() noexcept;

	virtual void		Init() override;
	virtual void		Update() override;
	virtual void		PhysicsUpdate() override;
	virtual void		Render(HDC hdc) override;
	virtual void		Release() override;
	
	bool				IsSetNextScene() const noexcept;

	void				SetNextScene(const std::wstring& name);
	void				ChangeScene();
private:
	Scene*							_currentScene = nullptr;
	Scene*							_nextScene = nullptr;
	std::unordered_map<std::wstring, Scene*>	_scenes;
};