#include "Stage.h"
#include "Road.h"
#include "Obstacle.h"
#include "Engine/Model.h"
#include "algorithm"
#include "random"

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
	//Instantiate<Obstacle>(this);
}

void Stage::Update()
{
	timer_ += 1.0 / 60.0;
	rTimer_ += 1.0 / 60.0;

	/*if (rTimer_ >= 0.85) {
		Instantiate<Road>(this);
		rTimer_ = 0.0;
	}*/
	if (timer_ >= 2.0) {
		std::random_shuffle(std::begin(xa), std::end(xa));
		for (int i = 0; i < 2; i++) {
			Instantiate<Obstacle>(this,xa[i]);
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
