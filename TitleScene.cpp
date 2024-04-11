#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void TitleScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	tPict_ = Image::Load("Picture\\title.png");
	assert(tPict_ >= 0);
}

//�X�V
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void TitleScene::Draw()
{
	Image::SetTransform(tPict_,transform_);
	Image::Draw(tPict_);
}

//�J��
void TitleScene::Release()
{
}
