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
	for (int i = 0; i < 11; i++) {
		Instantiate<Road>(this, i * 5);
	}
	//Instantiate<Obstacle>(this);
}

void Stage::Update()
{
	oTimer_ += 1.0 / 60.0;
	rTimer_ += 1.0 / 60.0;
	osTimer_ += 1.0 / 60.0;

	if (rTimer_ >= 0.8) {
		Instantiate<Road>(this,50);
		rTimer_ = 0.0;
	}
	if (oTimer_ >= 1.5) {
		std::random_shuffle(std::begin(xa), std::end(xa));
		if (osTimer_ >= 3.0) {
			speed_ += 0.02;
			osTimer_ = 0.0;
		}
		for (int i = 0; i < 2; i++) {
			Instantiate<Obstacle>(this,xa[i],speed_);
		}
		oTimer_ = 0.0;
	}
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
