#include "Result.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

ResultScene::ResultScene(GameObject* parent)
	:GameObject(parent,"ResultScene")
{
}

void ResultScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	rPict_ = Image::Load("Picture\\RESULT.png");
	assert(rPict_ >= 0);
}

void ResultScene::Update()
{
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
