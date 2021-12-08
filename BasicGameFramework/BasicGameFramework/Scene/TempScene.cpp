#include "TempScene.h"
#include "Layer.h"
#include "../Object/Player.h"

void TempScene::Init()
{
	Layer* mainLayer = new Layer(this, L"Main", 1);
	Player* player = new Player(this, mainLayer, L"Player");
	player->SetPosition(500, 500);

	mainLayer->AddObject(player);
	
	Scene::Init();
}