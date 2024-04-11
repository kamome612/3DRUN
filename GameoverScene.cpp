#include "GameoverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameoverScene::GameoverScene(GameObject* parent)
	:GameObject(parent,"GameoverScene")
{
}

void GameoverScene::Initialize()
{
	//画像データのロード
	gPict_ = Image::Load("Picture\\GAMEOVER.png");
	assert(gPict_ >= 0);
}

void GameoverScene::Update()
{
}

void GameoverScene::Draw()
{
	Image::SetTransform(gPict_, transform_);
	Image::Draw(gPict_);
}

void GameoverScene::Release()
{
}
