#include "Obstacle.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Obstacle::Obstacle(GameObject* parent)
	:GameObject(parent,"Obstacle"),hObs_(-1)
{
}

Obstacle::Obstacle(GameObject* parent, int x_ ,float s_)
	:GameObject(parent,"Obstacle"),hObs_(-1)
{
	transform_.position_.x = x_;
	speed_ = s_;
}

Obstacle::~Obstacle()
{
}

void Obstacle::Initialize()
{
	//���f���̓ǂݍ���
	hObs_ = Model::Load("Model\\Obs.fbx");
	assert(hObs_ >= 0);
	//�����蔻��̂��߂̃R���W�����̐ݒ�
	SphereCollider* collision = new SphereCollider({ 0,0.5,0 }, 0.4f);
	AddCollider(collision);
	//�ʒu�ƌ����̒���
	transform_.position_.y = 0.5;
	transform_.position_.z = 30;
	transform_.rotate_.y = 180;
	transform_.scale_ = XMFLOAT3(1.5, 1.5, 1.5);
}

void Obstacle::Update()
{
	/*timer_ += 1.0 / 60.0;
	if (timer_ >= 1.0) {
		speed_ += 0.2;
		timer_ = 0.0;
	}*/
	//��ʉ������O�ɏ������߂Â��Ă���
    transform_.position_.z -= speed_;
	if (transform_.position_.z < -5) {
		KillMe();
	}
}

void Obstacle::Draw()
{
	//���f���̕\��
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
