#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene")
{
}

//������
void ClearScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	cPict_ = Image::Load("Picture\\CLEAR.png");
	assert(cPict_ >= 0);
}

//�X�V
void ClearScene::Update()
{
}

//�`��
void ClearScene::Draw()
{
	Image::SetTransform(cPict_, transform_);
	Image::Draw(cPict_);
}

//�J��
void ClearScene::Release()
{
}
