#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//障害物(パックマン)
class Obstacle :
    public GameObject
{
    Text* pText_;
    int hObs_;
    float speed_;
public:
    //コンストラクタ
    Obstacle(GameObject* parent);
    //x座標とspeed付き
    Obstacle(GameObject* parent,int x_ ,float s_);
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

