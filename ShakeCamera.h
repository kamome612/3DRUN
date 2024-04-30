#pragma once
#include "Engine/GameObject.h"
#include "Engine/Camera.h"
class ShakeCamera :
    public GameObject
{
	float Duration;//�h�炷����
	float Strength;//�h��̋���
	float Vibrato; //�U���̒��x
	XMFLOAT3 initPosition;//�����ʒu
	XMFLOAT3 cameraPosition;//�ω������Ă������̈ʒu
	bool isDoShake;       //�h������s���Ă��邩
	float totalShakeTime; //�h��̌o�ߎ���
public:
	//�R���X�g���N�^
	ShakeCamera(GameObject* parent,float duration, float strength, float vibrato);

	//�f�X�g���N�^
	~ShakeCamera();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�J��
	void Release() override;
};

