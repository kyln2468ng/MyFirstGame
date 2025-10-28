#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
}

void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		GameObject* sceneOb = GameObject::FindObject("SceneManager");
		SceneManager* smgr = dynamic_cast<SceneManager*>(sceneOb);
		smgr->ChangeScene(SCENE_ID::SCENE_ID_PLAY);
	}
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
