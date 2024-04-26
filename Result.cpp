#include "Result.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

ResultScene::ResultScene(GameObject* parent)
	:GameObject(parent,"ResultScene")
{
}

void ResultScene::Initialize()
{
	//画像データのロード
	rPict_ = Image::Load("Picture\\RESULT.png");
	assert(rPict_ >= 0);
}

void ResultScene::Update()
{
	//T押されたらタイトルシーンに移動
	if (Input::IsKey(DIK_T)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
	//R押されたらプレイシーンに移動
	else if(Input::IsKey(DIK_R)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void ResultScene::Draw()
{
	//画像の表示
	Image::SetTransform(rPict_, transform_);
	Image::Draw(rPict_);
}

void ResultScene::Release()
{
}
