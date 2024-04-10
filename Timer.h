#pragma once
#include "Engine/GameObject.h"
class Timer :
    public GameObject
{
public:
    //コンストラクタ
    Timer(GameObject* parent);

    //デストラクタ
    ~Timer();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

