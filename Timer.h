#pragma once
#include "Engine/GameObject.h"
class Timer :
    public GameObject
{
public:
    //�R���X�g���N�^
    Timer(GameObject* parent);

    //�f�X�g���N�^
    ~Timer();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

