#pragma once

#include <string>
#include <vector>

#include "../IBehaviour.h"

class Scene;
class GameObject;

class Layer : IBehaviour
{
public:
	Layer(Scene* scene, const std::wstring& tag, INT32 zOrder);
	virtual ~Layer();

	virtual void		Init() override;
	virtual void		Update() override;
	virtual void		PhysicsUpdate() override;
	virtual void		Render(HDC hdc) override;
	virtual void		Release() override;

	const Scene*		GetScene() const noexcept;
	std::wstring		GetTag() const noexcept;
	INT32				GetZOrder() const noexcept;

	void				AddObject(GameObject* obj);
	void				RemoveObject(const wstring& tag);
private:
	Scene*					_scene;
	INT32					_zOrder;
	wstring					_tag;
	vector<GameObject*>		_objects;
};