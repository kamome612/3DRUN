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
	//���f���̓ǂݍ���
	hPlayer_ = Model::Load("Model\\sample.fbx");
	assert(hPlayer_ >= 0);
	//�����蔻��̂��߂̃R���W�����̐ݒ�
	SphereCollider* collision = new SphereCollider({ 0,0.3,0 }, 0.3f);
	AddCollider(collision);
	//�ʒu�Ƒ傫���̒���
	transform_.position_.y = 1.0;
	transform_.scale_ = XMFLOAT3(0.5, 0.5, 0.5);
}

void Player::Update()
{
	//A�������ꂽ�獶�Ɉړ�
	if (Input::IsKeyDown(DIK_A)) {
	//���ɍs���߂��Ȃ��悤��
		if (transform_.position_.x > -2) {
			transform_.position_.x -= 2;
		}
	}

	//D�������ꂽ��E�Ɉړ�
	else if (Input::IsKeyDown(DIK_D)) {
	//�E�ɍs���߂��Ȃ��悤��
		if (transform_.position_.x < 2)
			transform_.position_.x += 2;
	}
}

void Player::Draw()
{
	//���f���̕\��
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
