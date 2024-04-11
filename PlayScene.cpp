#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Road.h"
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
	Camera::SetPosition(XMFLOAT3(0, 3.5, -3));
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
	//timerの表示
	pText_ = new Text;
	pText_->Initialize();
}

//更新
void PlayScene::Update()
{
	timer_ -= 1.0 / 60.0;
	if (timer_ <= 0) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
	if (FindObject("Player") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

//描画
void PlayScene::Draw()
{
	pText_->Draw(30, 30, timer_);
}

//開放
void PlayScene::Release()
{
}
