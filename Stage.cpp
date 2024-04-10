#include "Stage.h"
#include "Road.h"
#include "Obstacle.h"
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
	for (int i = 0; i < 2; i++) {
		Instantiate<Obstacle>(this);
	}
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
