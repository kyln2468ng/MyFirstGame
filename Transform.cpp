#include "Transform.h"

Transform::Transform()
{
    position_ = { 0, 0, 0 };
    rotate_   = { 0, 0, 0 };
    scale_    = { 1.0f, 1.0f, 1.0f };
}

Transform::~Transform()
{
}

void Transform::Calculation()
{
    matTranslate_= XMMatrixTranslation(position_.x, position_.y, position_.z);
    
    XMMATRIX r1, r2, r3;
    r1 = XMMatrixRotationZ(XMConvertToRadians(rotate_.z));
    r2 = XMMatrixRotationY(XMConvertToRadians(rotate_.y));
    r3 = XMMatrixRotationX(XMConvertToRadians(rotate_.x));
    matRotate_ = (r1 * r2 * r3);
    
    matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);

}

XMMATRIX Transform::GetWorldMatrix()
{
    return (matScale_ * matRotate_ * matTranslate_); // ägèkÅñâÒì]Åñà⁄ìÆ
}                   
