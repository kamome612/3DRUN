#pragma once
#include "Engine/GameObject.h"
#include "Engine/Camera.h"
class ShakeCamera :
    public GameObject
{
	float Duration;//揺らす時間
	float Strength;//揺れの強さ
	float Vibrato; //振動の程度
	XMFLOAT3 initPosition;//初期位置
	XMFLOAT3 cameraPosition;//変化させていく方の位置
	bool isDoShake;       //揺れを実行しているか
	float totalShakeTime; //揺れの経過時間
public:
	//コンストラクタ
	ShakeCamera(GameObject* parent,float duration, float strength, float vibrato);

	//デストラクタ
	~ShakeCamera();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//開放
	void Release() override;
};

