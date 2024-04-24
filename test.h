#pragma once
#include "Engine/GameObject.h"
class test :
    public GameObject
{
    int hModel_;
public:
    //コンストラクタ
    test(GameObject* parent);

    test(GameObject* parent, int z_);

    //デストラクタ
    ~test();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

