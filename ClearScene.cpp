#include "ClearScene.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),hModel_(-1)
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	hModel_ = Model::Load("Clear.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 1.0f,1.0f,1.0f };
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_T))
	{
		SceneManager* sceneOb = (SceneManager*)FindObject("SceneManager");
		sceneOb->ChangeScene(SCENE_ID_TEST);
	}
}

void ClearScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void ClearScene::Release()
{
	KillMe();
}
