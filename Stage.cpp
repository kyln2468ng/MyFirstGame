#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

namespace
{
	const int ENEMY_NUM = 2;
}

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage")
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	Instantiate<Player>(this);
	enemy_ = std::vector<Enemy*>(ENEMY_NUM);
	for (int i = 0;i < ENEMY_NUM;i++)
	{
		int x = 0;
		x = rand() % 11;
		if (i % 2 == 0)
		{
			x = -x;
		}
		
		enemy_[i] = (Enemy*)Instantiate<Enemy>(this);
		enemy_[i]->SetPosition((float)x, 0.0f, 50.0f);
	}

}

void Stage::Update()
{
	for (auto it = enemy_.begin(); it != enemy_.end(); )
	{
		Enemy* e = *it;
		if (e->isDed())
		{
			it = enemy_.erase(it); // ベクターから削除
		}
		else
		{
			++it;
		}
	}

	if (enemy_.empty())
	{
		KillMe();
		SceneManager* sceneOb = (SceneManager*)FindObject("SceneManager");
		sceneOb->ChangeScene(SCENE_ID_CLEAR);
	}
}

void Stage::Draw()
{
}

void Stage::Release()
{
}

void Stage::OnCollision(GameObject* pTarget)
{
	
}
