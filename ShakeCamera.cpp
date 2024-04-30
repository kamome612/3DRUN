#include "ShakeCamera.h"

ShakeCamera::ShakeCamera(GameObject* parent,float duration,float strength,float vibrato)
{
	initPosition = Camera::GetPosition();
	cameraPosition = Camera::GetPosition();
	Duration = duration;
	Strength = strength;
	Vibrato = vibrato;
}

ShakeCamera::~ShakeCamera()
{
}

void ShakeCamera::Initialize()
{
}

void ShakeCamera::Update()
{
	if (isDoShake) {
		
	}
}

void ShakeCamera::Release()
{
}
