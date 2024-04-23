#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hPlayer_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//モデルの読み込み
	hPlayer_ = Model::Load("Model\\sample.fbx");
	assert(hPlayer_ >= 0);
	//当たり判定のためのコリジョンの設定
	SphereCollider* collision = new SphereCollider({ 0,0.3,0 }, 0.3f);
	AddCollider(collision);
	//位置と大きさの調整
	transform_.position_.y = 1.0;
	transform_.scale_ = XMFLOAT3(0.5, 0.5, 0.5);
}

void Player::Update()
{
	//Aが押されたら左に移動
	if (Input::IsKeyDown(DIK_A)) {
	//左に行き過ぎないように
		if (transform_.position_.x > -2) {
			transform_.position_.x -= 2;
		}
	}

	//Dが押されたら右に移動
	else if (Input::IsKeyDown(DIK_D)) {
	//右に行き過ぎないように
		if (transform_.position_.x < 2)
			transform_.position_.x += 2;
	}
}

void Player::Draw()
{
	//モデルの表示
	Model::SetTransform(hPlayer_, transform_);
	Model::Draw(hPlayer_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Obstacle") {
		this->KillMe();
	}
}
