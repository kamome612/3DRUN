#include "CDTIMER.h"
#include "Engine/GameObject.h"

CDTIMER::CDTIMER(GameObject* parent)
{
	
	TIMER_INIT_TIME_ = DEF_TIMER_INTERVAL;
	CDTimer_ = DEF_TIMER_INTERVAL;
	isTimerRun_ = true;
	DEC_TIMER = 1.0 / 60.0;
}

CDTIMER::CDTIMER(GameObject* parent, double _time)
{
	TIMER_INIT_TIME_ = _time;
	CDTimer_ = _time;
	isTimerRun_ = true;
	DEC_TIMER = 1.0 / 60.0;
}

CDTIMER::~CDTIMER()
{
}

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
