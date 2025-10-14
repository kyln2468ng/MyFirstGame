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
	//0.������`��
	Draw(); // this->Draw(); �ǂ���ɂ��邩�͏ꏊ���ƂňႤ
	//1.�q�I�u�W�F�N�g��`�� childList_�̊e�v�f�ɑ΂���Draw���Ă�
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
