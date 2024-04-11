#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene")
{
}

//初期化
void ClearScene::Initialize()
{
	//画像データのロード
	cPict_ = Image::Load("Picture\\CLEAR.png");
	assert(cPict_ >= 0);
}

//更新
void ClearScene::Update()
{
}

//描画
void ClearScene::Draw()
{
	Image::SetTransform(cPict_, transform_);
	Image::Draw(cPict_);
}

//開放
void ClearScene::Release()
{
}
