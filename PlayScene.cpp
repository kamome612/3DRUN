#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Road.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	//�J�����̎��_�ύX
	Camera::SetPosition(XMFLOAT3(0, 3.5, -3));
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
