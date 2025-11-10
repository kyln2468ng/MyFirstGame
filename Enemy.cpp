#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Fbx.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),pFbx_(nullptr),hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("rCubes.fbx");
	assert(hModel_ >= 0);
	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;
	transform_.position_.x = 5.0f;
}

void Enemy::Update()
{
	//transform_.position_.x -= 0.5f;
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
	if(pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
