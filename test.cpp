#include "test.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

test::test(GameObject* parent)
	:GameObject(parent,"test"),hModel_(-1)
{
}

test::test(GameObject* parent, int z_)
	:GameObject(parent,"test"),hModel_(-1)
{
	transform_.position_.z = z_;
}

test::~test()
{
}

void test::Initialize()
{
	hModel_ = Model::Load("Model\\road.fbx");
	assert(hModel_ >= 0);
	transform_.position_.z = 5;
}

void test::Update()
{
	if (Input::IsKey(DIK_W)) {
		transform_.position_.z += 0.1;
	}
	if (Input::IsKey(DIK_S)) {
		transform_.position_.z -= 0.1;
	}
	if (Input::IsKey(DIK_LEFT)) {
		transform_.rotate_.y -= 0.5;
	}
	if (Input::IsKey(DIK_RIGHT)) {
		transform_.rotate_.y += 0.5;
	}
}

void test::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void test::Release()
{
}
