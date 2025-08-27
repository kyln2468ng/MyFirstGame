#include "Dice.h"
#include <DirectXMath.h>

using namespace DirectX;

Dice::Dice()
    :Quad()
{
}

Dice::~Dice()
{
}

HRESULT Dice::Initialize()
{
	VERTEX vertices[] =
	{
		// 面1 正面
		{ XMVectorSet(-1.0f,  1.0f, -1.0f, 1.0f),XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f) },   // 四角形の頂点（左上）
		{ XMVectorSet(1.0f,  1.0f,-1.0f, 1.0f),	XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f) },   // 四角形の頂点（右上）
		{ XMVectorSet(1.0f, -1.0f, -1.0f, 1.0f),XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f) },   // 四角形の頂点（右下）
		{ XMVectorSet(-1.0f, -1.0f, -1.0f, 1.0f),XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f) },   // 四角形の頂点（左下）

		// 面2 上面
		{ XMVectorSet(-1.0f,  1.0f,  1.0f, 1.0f),XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f) },
		{ XMVectorSet(1.0f,  1.0f,  1.0f, 1.0f),XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f) },
		{ XMVectorSet(1.0f,  1.0f, -1.0f, 1.0f),XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f) },
		{ XMVectorSet(-1.0f,  1.0f,  -1.0f, 1.0f),XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f) },

		// 面3 右面
		{ XMVectorSet(1.0f,   1.0f, -1.0f, 1.0f),XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f) },
		{ XMVectorSet(1.0f,   1.0f,  1.0f, 1.0f),XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f) },
		{ XMVectorSet(1.0f,  -1.0f,  1.0f, 1.0f),XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f) },
		{ XMVectorSet(1.0f,  -1.0f, -1.0f, 1.0f),XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f) },

		// 面4 下面
		{ XMVectorSet(-1.0f,  -1.0f, -1.0f, 1.0f),XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f) },
		{ XMVectorSet(1.0f,  -1.0f, -1.0f, 1.0f),XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f) },
		{ XMVectorSet(1.0f,  -1.0f, 1.0f, 1.0f),XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f) },
		{ XMVectorSet(-1.0f,  -1.0f, 1.0f, 1.0f),XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f) },

		// 面5 左面
		{ XMVectorSet(-1.0f,  1.0f, 1.0f, 1.0f),XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f) },
		{ XMVectorSet(-1.0f,  1.0f, -1.0f, 1.0f),XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f) },
		{ XMVectorSet(-1.0f,  -1.0f, -1.0f, 1.0f),XMVectorSet(1.0f, 0.5f, 0.0f, 0.0f) },
		{ XMVectorSet(-1.0f,  -1.0f, 1.0f, 1.0f),XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f) },

		// 面6 裏面
		{ XMVectorSet(1.0f,  1.0f, 1.0f, 1.0f),XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f) },
		{ XMVectorSet(-1.0f,  1.0f, 1.0f, 1.0f),XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f) },
		{ XMVectorSet(-1.0f,  -1.0f, 1.0f, 1.0f),XMVectorSet(0.5f, 1.0f, 0.0f, 0.0f) },
		{ XMVectorSet(1.0f,  -1.0f, 1.0f, 1.0f),XMVectorSet(0.250f, 1.0f, 0.0f, 0.0f) },

	};

	HRESULT hr;
	// 頂点データ用バッファの設定
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(vertices);
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices;
	hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"頂点バッファの作成に失敗しました", L"エラー", MB_OK);
		return hr;
	}

	//インデックス情報
	int index[] = { 0,2,3, 0,1,2, 	// 正面
					4,6,7, 4,5,6,	// 上面
					8,10,11, 8,9,10,	// 右面
					12,14,15, 12,13,14,	// 下面
					16,18,19, 16,17,18,	// 左面
					20,22,23, 20,21,22 }; // 裏面 
	// CW ※時計回り

	// インデックスバッファを生成する
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(index);
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"インデックスバッファの作成に失敗しました", L"エラー", MB_OK);
		return hr;
	}

	//コンスタントバッファ作成
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// コンスタントバッファの作成
	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"コンスタントバッファの作成に失敗しました", L"エラー", MB_OK);
		return hr;
	}

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
