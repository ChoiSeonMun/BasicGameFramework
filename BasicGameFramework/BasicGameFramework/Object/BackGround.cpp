#include "../stdafx.h"

#include "../Component/RectComponent.h"

#include "BackGround.h"

bool BackGround::Init()
{
	if (false == GameObject::Init())
	{
		return false;
	}

	SetPosition(POINT{ 0, 0 });

	RectComponent* rectComp = new RectComponent(this, 0, Size{ 1280, 720 }, Pivot::LeftTop);

}