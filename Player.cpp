#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hPlayer_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hPlayer_ = Model::Load("Model\\sample.fbx");
	assert(hPlayer_ >= 0);
}

void Player::Update()
{
	if (Input::IsKey(DIK_W)) {
		transform_.position_.z += 0.5;
	}
	else if (Input::IsKey(DIK_A)) {
		transform_.position_.x -= 0.5;
	}
	else if (Input::IsKey(DIK_S)) {
		transform_.position_.z -= 0.5;
	}
	else if (Input::IsKey(DIK_D)) {
		transform_.position_.x += 0.5;
	}
}

void Player::Draw()
{
	Model::SetTransform(hPlayer_, transform_);
	Model::Draw(hPlayer_);
}

void Player::Release()
{
}
