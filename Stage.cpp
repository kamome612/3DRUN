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
	//transform_.position_.z -= 0.1;
	/*if (FindObject("Obstacle") == nullptr) {
		Instantiate<Obstacle>(this);
	}*/
	timer_ += 1.0 / 60.0;
	rTimer_ += 1.0 / 60.0;

	if (rTimer_ >= 0.85) {
		Instantiate<Road>(this);
		rTimer_ = 0.0;
	}
	if (timer_ >= 2.0) {
		for (int i = 0; i < 2; i++) {
			Instantiate<Obstacle>(this);
		}
		timer_ = 0.0;
	}
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
