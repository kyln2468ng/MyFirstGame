#include "Dice.h"

Dice::Dice()
{
}

Dice::~Dice()
{
}

HRESULT Dice::Initialize()
{
    pTexture_ = new Texture;
    pTexture_->Load("Assets\\Dice.png");
    return S_OK;
}

void Dice::Draw(XMMATRIX& worldMatrix)
{
}

void Dice::Release()
{
}
