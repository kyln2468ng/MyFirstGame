#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"

namespace
{
	const int ENEMY_NUM = 2;
}

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hModel_(-1)
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	hModel_ = Model::Load("texture.fbx");
	assert(hModel_ >= 0);
	transform_.position_= { 0.0f,-8.0f,5.0f};

	transform_.scale_ = { 1.0f,1.0f,1.0f };

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
	RayCastData data;
	Player* p = (Player*)FindObject("Player");
	XMFLOAT3 pPos = p->GetPos();
	XMStoreFloat4(&data.start,XMLoadFloat3(&pPos));
	XMVECTOR dir = XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f);
	XMStoreFloat4(&data.dir, dir);


	Transform trans;
	trans.position_.x = 0.0f;
	trans.position_.y = -8.0f;
	trans.position_.z = 5.0f;
	Model::SetTransform(hModel_, trans);
	Model::RayCast(hModel_, data);
	
	//⑥ レイが当たったらブレークポイントで止める
	if (data.isHit)
	{
		//なんか書いてないとifに当たらないから、
		int a = 0;
		a++;
	}

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
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Stage::Release()
{
	KillMe();
}

void Stage::OnCollision(GameObject* pTarget)
{
	
}
