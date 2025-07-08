#pragma once
#include "Direct3D.h"

#include <DirectXMath.h>
#include "Camera.h"
#include "Texture.h"
#include "Dice.h"

using namespace DirectX;

//コンスタントバッファー

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
};

//頂点情報
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
};

// 前方宣言
class Texture; // Textureクラスってのがどこかにあってだなぁっていう宣言

class Quad
{
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(XMMATRIX& worldMatrix);
	virtual void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ / 定数バッファ
	Texture* pTexture_;
};