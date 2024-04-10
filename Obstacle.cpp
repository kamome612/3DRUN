#include "Obstacle.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Obstacle::Obstacle(GameObject* parent)
	:GameObject(parent,"Obstacle"),hObs_(-1)
{
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
	SphereCollider* collision = new SphereCollider({ 0,0.3,0 }, 0.3f);
	AddCollider(collision);
	//位置と向きの調整
	int x = rand() % 3;
	switch (x) {
	case 0:
		transA = -2;
		transB = 0;
		break;
	case 1:
		transA = 0;
		transB = 2;
		break;
	case 2:
		transA = -2;
		transB = 2;
		break;
	default:
		break;
	}
	transform_.position_.y = 1.0;
	transform_.position_.z = 15;
	transform_.rotate_.y = 180;
}

void Obstacle::Update()
{
	//画面奥から手前に少しずつ近づいてくる
	transform_.position_.z -= 0.05;
	if (transform_.position_.z < -5) {
		KillMe();
	}
}

void Obstacle::Draw()
{
	//モデルの表示
	for (int i = 0; i < 2; i++) {
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
	}
}

void Obstacle::Release()
{
}
