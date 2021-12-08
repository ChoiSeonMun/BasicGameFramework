#include "TempScene.h"
#include "Layer.h"

#include "../Object/Player.h"
#include "../Object/Obstacle.h"

void TempScene::Init()
{
	Layer* mainLayer = new Layer(this, L"Main", 1);

	Obstacle* obstacle = new Obstacle(this, mainLayer, L"Obstacle");
	obstacle->SetPosition(700, 400);

	Player* player = new Player(this, mainLayer, L"Player");
	player->SetPosition(500, 500);

	
	Scene::Init();
}