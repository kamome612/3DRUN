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
	Instantiate<Obstacle>(this);
}

void Stage::Update()
{
	/*if (FindObject("Obstacle") == nullptr) {
		Instantiate<Obstacle>(this);
	}*/
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
