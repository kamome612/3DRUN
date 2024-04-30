#pragma once
#include "Engine/GameObject.h"
const double DEF_TIMER_INTERVAL{ 1 / 24.0 };

class CDTIMER :public GameObject
{
	double TIMER_INIT_TIME_;
	bool isTimerRun_;
	double DEC_TIMER;
public:
	//コンストラクタ
	CDTIMER(GameObject* parent);
	CDTIMER(GameObject* parent, double _time);
	//デストラクタ
	~CDTIMER();
	double CDTimer_;
	//タイマーが0になったか
	bool IsTimeOver();
	//タイマーをリセットする
	void ResetTimer();
	//タイマーをスタートさせる
	void StartTimer();
	//タイマーを止める
	void StopTimer();


	 //初期化
    void Initialize() override;
    //描画
    void Draw() override;
    //開放
    void Release() override;
	//更新
	void Update() override;
};
