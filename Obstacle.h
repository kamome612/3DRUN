#pragma once
#include "Engine/GameObject.h"
//障害物(パックマン)
class Obstacle :
    public GameObject
{
    int hObs_;
public:
    //コンストラクタ
    Obstacle(GameObject* parent);

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

