#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Road.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),timer_(30.0)
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	//カメラの視点変更
	Camera::SetPosition(XMFLOAT3(0, 3.5, -5));
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
}

//更新
void PlayScene::Update()
{
	//Playerが死んだらResultSceneに移行
	if (FindObject("Player") ==nullptr) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}

	if (Input::IsKey(DIK_UP) ){
		spc.y += 0.5;
	}
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
