#include "CDTIMER.h"
#include "Engine/GameObject.h"

bool CDTIMER::IsTimeOver()
{
	return(CDTimer_ < 0);
}

void CDTIMER::ResetTimer()
{
	CDTimer_ = TIMER_INIT_TIME_;
	StartTimer();
}

void CDTIMER::StartTimer()
{
	isTimerRun_ = true;
}

void CDTIMER::StopTimer()
{
	isTimerRun_ = false;
}

void CDTIMER::Initialize()
{
}

void CDTIMER::Draw()
{
}

void CDTIMER::Release()
{
}

void CDTIMER::Update()
{
	if (isTimerRun_){
		CDTimer_ = CDTimer_ - DEC_TIMER;
	}
}
