#pragma once
#include "Engine/GameObject.h"
//��Q����v���C���[�̂��铹
class Road :
    public GameObject
{
    int hRoad_;
public:
    //�R���X�g���N�^
    Road(GameObject* parent);

    //�f�X�g���N�^
    ~Road();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

