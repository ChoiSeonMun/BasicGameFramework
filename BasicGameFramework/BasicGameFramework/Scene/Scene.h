#pragma once

#include <string>
#include <vector>

#include "../IBehaviour.h"

class Layer;

class Scene abstract : IBehaviour
{
public:
	Scene(const std::wstring& name);
	virtual ~Scene();

	virtual void		Init() override;
	virtual void		Update() override;
	virtual void		PhysicsUpdate() override;
	virtual void		Render(HDC hdc) override;
	virtual void		Release() override;

	void				AddLayer(Layer* layer);
	void				RemoveLayer(const std::wstring& tag);
	Layer*				FindLayer(const std::wstring& tag);
private:
	std::wstring			_name;
	std::vector<Layer*>		_layers;
};