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
	Camera::SetPosition(XMFLOAT3(0, 3.5, -5));
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
	//timerの表示
	pText_ = new Text;
	pText_->Initialize();
}

//更新
void PlayScene::Update()
{
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
