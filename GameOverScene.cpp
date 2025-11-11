#include "GameOverScene.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"GameOverSCene"),hModel_(-1)
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Initialize()
{
	hModel_ = Model::Load("rCubes.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.1f,0.1f,0.1f };
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_T))
	{
		SceneManager* sceneOb = (SceneManager*)FindObject("SceneManager");
		sceneOb->ChangeScene(SCENE_ID_TEST);
	}
}

void GameOverScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void GameOverScene::Release()
{
	KillMe();
}
