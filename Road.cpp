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
	hRoad_ = Model::Load("Model\\road.fbx");
	assert(hRoad_ >= 0);
}

void Road::Update()
{
}

void Road::Draw()
{
	Model::SetTransform(hRoad_, transform_);
	Model::Draw(hRoad_);
}

void Road::Release()
{
}
