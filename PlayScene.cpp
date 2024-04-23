#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Road.h"
#include "Engine/Input.h"
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
}

//�X�V
void PlayScene::Update()
{
	//Player�����񂾂�ResultScene�Ɉڍs
	if (FindObject("Player") ==nullptr) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}

	if (Input::IsKey(DIK_UP) ){
		spc.y += 0.5;
	}
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
