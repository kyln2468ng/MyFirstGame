#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const string& name)
	:pParent_(parent), objectName_(name)
{
}

GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	Update();
	for (auto child : childList_)
	{
		child->UpdateSub();
	}
}

void GameObject::DrawSub()
{
	//0.自分を描画
	Draw(); // this->Draw(); どちらにするかは場所ごとで違う
	//1.子オブジェクトを描画 childList_の各要素に対してDrawを呼ぶ
	/*for (auto it = childList_.begin();it != childList_.end(); ++it)
	{
		(*it)->DrawSub();
	}*/

	for (auto child : childList_)
	{
		child->DrawSub();
	}
}

//void GameObject::ReleaseSub()
//{
//	Release();
//
//}
