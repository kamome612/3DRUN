#include "Stage.h"
#include "Road.h"
#include "Engine/Model.h"

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage")
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	Instantiate<Road>(this);
}

void Stage::Update()
{
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
