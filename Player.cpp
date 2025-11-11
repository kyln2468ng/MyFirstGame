#include "Player.h"
#include "ChildOden.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"
#include "Bullet.h"
#include "Engine/SceneManager.h"

namespace
{
	float coolTime_ = 1.0f;
	const float deltatime_ = 0.016;
}

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
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

	SphereCollider* col = new SphereCollider(0.5f);
	AddCollider(col);
}

void Player::Update()
{
	//transform_.rotate_.y += 1.0f;
	/*if (transform_.rotate_.y >= 720.0f)
	{
		KillMe();
	}*/
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.z += 0.1;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.1f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.1f;
	}

	coolTime_ -= deltatime_;
	if (Input::IsKeyDown(DIK_SPACE) && coolTime_ < 0.0f)
	{
		bullet_ = (Bullet*)Instantiate<Bullet>(FindObject("PlayScene"));
		bullet_->SetPosition(transform_.position_);
		coolTime_ = 1.0f;
	}

	// 敵が複数体の場合も想定して、プレイヤー側は毎ループ呼ぶのは敵が0かどうかのブール？

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
	KillMe();
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->FindObject("Enemy"))
	{
		this->Release();
		SceneManager* sceneOb = (SceneManager*)FindObject("SceneManager");
		sceneOb->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

