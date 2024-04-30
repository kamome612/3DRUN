#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Road.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),pText_(nullptr)
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	//Instantiate<test>(this);
	pText_ = new Text;
	pText_->Initialize();
}

//�X�V
void PlayScene::Update()
{	
	//Player�����񂾂�ResultScene�Ɉڍs
	if (FindObject("Player") ==nullptr) {
		if (timer > 2.0) {
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_RESULT);
		}
		timer += 1.0 / 60.0;
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
