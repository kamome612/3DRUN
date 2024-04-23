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
	speed_ = 0.1;
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
		if (rTimer_ >= 5.0) {
			speed_ += 0.05;
			rTimer_ = 0.0;
		}
		for (int i = 0; i < 2; i++) {
			Instantiate<Obstacle>(this,xa[i],speed_);
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
