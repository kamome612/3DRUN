#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Road.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),timer_(30.0)
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	//�J�����̎��_�ύX
	Camera::SetPosition(XMFLOAT3(0, 3.5, -5));
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
	//timer�̕\��
	pText_ = new Text;
	pText_->Initialize();
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
	pText_->Draw(30, 30, timer_);
}

//�J��
void PlayScene::Release()
{
}
