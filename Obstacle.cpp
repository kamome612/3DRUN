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
	//���f���̓ǂݍ���
	hObs_ = Model::Load("Model\\Obs.fbx");
	assert(hObs_ >= 0);
	//�����蔻��̂��߂̃R���W�����̐ݒ�
	SphereCollider* collision = new SphereCollider({ 0,0.3,0 }, 0.3f);
	AddCollider(collision);
	//�ʒu�ƌ����̒���
	int x = rand() % 3;
	transform_.position_.x = 2 * (x - 1);
	transform_.position_.y = 1.0;
	transform_.position_.z = 10;
	transform_.rotate_.y = 180;
}

void Obstacle::Update()
{
	//��ʉ������O�ɏ������߂Â��Ă���
	transform_.position_.z -= 0.05;
}

void Obstacle::Draw()
{
	//���f���̕\��
	Model::SetTransform(hObs_, transform_);
	Model::Draw(hObs_);
}

void Obstacle::Release()
{
	/*if (transform_.position_.z < 5) {
		KillMe();
	}*/
}
