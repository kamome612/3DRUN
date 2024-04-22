#pragma once
#include "Engine/GameObject.h"
//障害物(パックマン)
class Obstacle :
    public GameObject
{
    int hObs_;
    double timer_;
public:
    //コンストラクタ
    Obstacle(GameObject* parent);
    //コンストラクタ(x座標付)
    Obstacle(GameObject* parent,int x_);

    //デストラクタ
    ~Obstacle();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

