#include "Road.h"
#include "Engine/Model.h"

Road::Road(GameObject* parent)
	:GameObject(parent,"Road"),hRoad_(-1)
{
}

Road::~Road()
{
}

void Road::Initialize()
{
	//���f���̓ǂݍ���
	hRoad_ = Model::Load("Model\\road.fbx");
	assert(hRoad_ >= 0);
	//�ʒu�̒���
	transform_.position_.y = 0;
	transform_.position_.z = 10;
}

void Road::Update()
{
}

void Road::Draw()
{
	//���f���̕\��
	Model::SetTransform(hRoad_, transform_);
	Model::Draw(hRoad_);
}

void Road::Release()
{
}
