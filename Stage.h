#pragma once
#include "Engine/GameObject.h"
#include <vector>

class Enemy;
class Player;

class Stage : public GameObject
{
public:
	Stage(GameObject* parent);
	~Stage();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget) override;

private:
	std::vector<Enemy*> enemy_;
	int hModel_;
};