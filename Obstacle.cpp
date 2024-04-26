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
	//���f���̓ǂݍ���
	hObs_ = Model::Load("Model\\Obs.fbx");
	assert(hObs_ >= 0);
	//�����蔻��̂��߂̃R���W�����̐ݒ�
	SphereCollider* collision = new SphereCollider({ 0,0.5,0 }, 0.4f);
	AddCollider(collision);
	//�ʒu������A�傫���̒���
	transform_.position_.y = 5;
	transform_.position_.z = 30;
	transform_.rotate_.y = 180;
	transform_.scale_ = XMFLOAT3(1.5, 1.5, 1.5);
}

void Obstacle::Update()
{
	//�o�Ă������ɏォ�痎���Ă���悤��
	if (transform_.position_.y > 0.5) {
		transform_.position_.y -= 0.2;
	}
	//���������Ă߂荞�񂾂肵�Ȃ��悤��
	else if(transform_.position_.y < 0.5) {
		transform_.position_.y = 0.5;
	}

	//��ʉ������O�ɏ������߂Â��Ă���
	if (transform_.position_.y == 0.5) {
		transform_.position_.z -= speed_;
	}

	//��ʊO�ɏo�������
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
