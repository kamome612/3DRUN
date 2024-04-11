#pragma once
#include "Engine/GameObject.h"
class GameoverScene :
    public GameObject
{
	int gPict_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameoverScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

