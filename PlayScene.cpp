#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Stage.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	//Player* pPlayer = new Player(this);
	//pPlayer->Initialize();
	//childList_.push_back(pPlayer);

	/*Instantiate<Player>(this);
	Instantiate<Enemy>(this);*/
	Instantiate<Stage>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
