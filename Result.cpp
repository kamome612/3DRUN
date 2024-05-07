#include "Result.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Player.h"

ResultScene::ResultScene(GameObject* parent)
	:GameObject(parent,"ResultScene"),pText_(nullptr)
{
}

void ResultScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	rPict_ = Image::Load("Picture\\RESULT.png");
	assert(rPict_ >= 0);

	pText_ = new Text;
	pText_->Initialize();
}

void ResultScene::Update()
{
	//T�����ꂽ��^�C�g���V�[���Ɉړ�
	if (Input::IsKey(DIK_T)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
	//R�����ꂽ��v���C�V�[���Ɉړ�
	else if(Input::IsKey(DIK_R)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void ResultScene::Draw()
{
	//�摜�̕\��
	Image::SetTransform(rPict_, transform_);
	Image::Draw(rPict_);
}

void ResultScene::Release()
{
}
