#include "Obstacle.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Obstacle::Obstacle(GameObject* parent)
	:GameObject(parent,"Obstacle"),hObs_(-1)
{
}

Obstacle::Obstacle(GameObject* parent, int x_)
	:GameObject(parent,"Obstacle"),hObs_(-1)
{
	transform_.position_.x = x_;
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
	//int x = rand() % 3;//����
	//x = 2 * (x - 1);
	//transform_.position_.x = x;
	//switch (x) {
	//case 0://�Z�Z�� �p�^�[��
	//	transA = -2;
	//	transB = 0;
	//	break;
	//case 1://���Z�Z �p�^�[��
	//	transA = 0;
	//	transB = 2;
	//	break;
	//case 2://�Z���Z �p�^�[��
	//	transA = -2;
	//	transB = 2;
	//	break;
	//default:
	//	break;
	//}
	transform_.position_.y = 1.0;
	transform_.position_.z = 20;
	transform_.rotate_.y = 180;
}

void Obstacle::Update()
{
	//��ʉ������O�ɏ������߂Â��Ă���
    transform_.position_.z -= 0.1;
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
