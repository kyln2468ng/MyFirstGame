#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"


TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene"), pFbx_(nullptr), hModel_(-1)
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
	hModel_ = Model::Load("rCubes.fbx");
	assert(hModel_ >= 0);
	transform_.scale_.x = 1.0f;
	transform_.scale_.y = 1.0f;
	transform_.scale_.z = 1.0f;
}

void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		//GameObject* sceneOb = GameObject::FindObject("SceneManager");
		//SceneManager* smgr = dynamic_cast<SceneManager*>(sceneOb);

		SceneManager* sceneOb = (SceneManager*)FindObject("SceneManager");
		sceneOb->ChangeScene(SCENE_ID_PLAY);
	}

	transform_.rotate_.y += 1.0f;
}

void TestScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TestScene::Release()
{
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
