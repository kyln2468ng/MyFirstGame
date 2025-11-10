#include "Player.h"
#include "Engine/Fbx.h"
#include "ChildOden.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), pFbx_(nullptr),hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//pFbx_ = new Fbx;
	//pFbx_がnullptrじゃなかった時のチェックあったほういい
	//pFbx_->Load("OdenA.fbx");
	hModel_ = Model::Load("OdenA.fbx");
	assert(hModel_ >= 0);
	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;

	//子オブジェクトにChildOdenを追加する
	pRChildOden = (ChildOden*)Instantiate<ChildOden>(this);
	pLChildOden = (ChildOden*)Instantiate<ChildOden>(this);
	pRChildOden->SetPosition(2.0f, 1.0f, 0.0f);
	pLChildOden->SetPosition(-2.0f, 1.0f, 0.0f);

	SphereCollider* col = new SphereCollider(0.6f);
	AddCollider(col);
}

void Player::Update()
{
	transform_.rotate_.y += 1.0f;
	/*if (transform_.rotate_.y >= 720.0f)
	{
		KillMe();
	}*/
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.z += 0.1;
	}
}

void Player::Draw()
{
	/*if (pFbx_)
	{
		pFbx_->Draw(transform_);
	}*/
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
