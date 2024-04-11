#pragma once
#include "Engine/GameObject.h"
//ステージのもろもろ
class Stage :
    public GameObject
{
    double timer_;
    double rTimer_;
public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

