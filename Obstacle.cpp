#include "Obstacle.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Obstacle::Obstacle(GameObject* parent)
	:GameObject(parent,"Obstacle"),hObs_(-1),pText_(nullptr)
{
}

Obstacle::Obstacle(GameObject* parent, int x_ ,float s_)
	:GameObject(parent,"Obstacle"),hObs_(-1),pText_(nullptr)
{
	transform_.position_.x = x_;
	speed_ = s_;
}

Obstacle::~Obstacle()
{
}

void Obstacle::Initialize()
{
	//モデルの読み込み
	hObs_ = Model::Load("Model\\Obs.fbx");
	assert(hObs_ >= 0);
	//当たり判定のためのコリジョンの設定
	SphereCollider* collision = new SphereCollider({ 0,0.5,0 }, 0.4f);
	AddCollider(collision);
	//位置や向き、大きさの調整
	transform_.position_.y = 5;
	transform_.position_.z = 30;
	transform_.rotate_.y = 180;
	transform_.scale_ = XMFLOAT3(1.5, 1.5, 1.5);
}

void Obstacle::Update()
{
	//出てきた時に上から落ちてくるように
	if (transform_.position_.y > 0.5) {
		transform_.position_.y -= 0.2;
	}
	//落ちすぎてめり込んだりしないように
	else if(transform_.position_.y < 0.5) {
		transform_.position_.y = 0.5;
	}

	//画面奥から手前に少しずつ近づいてくる
	if (transform_.position_.y == 0.5) {
		transform_.position_.z -= speed_;
	}

	//画面外に出たら消す
	if (transform_.position_.z < -5) {
		KillMe();
	}
}

void Obstacle::Draw()
{
	//モデルの表示
	Model::SetTransform(hObs_, transform_);
	Model::Draw(hObs_);
	/*for (int i = 0; i < 2; i++) {
		if (i == 0) {
			transform_.position_.x = transA;
			Model::SetTransform(hObs_, transform_);
			Model::Draw(hObs_);
		}
		else {
			transform_.position_.x = transB;
			Model::SetTransform(hObs_, transform_);
			Model::Draw(hObs_);
		}
	}*/
}

void Obstacle::Release()
{
}
