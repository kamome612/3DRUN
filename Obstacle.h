#pragma once
#include "Engine/GameObject.h"
//��Q��(�p�b�N�}��)
class Obstacle :
    public GameObject
{
    int hObs_;
    int transA, transB;
public:
    //�R���X�g���N�^
    Obstacle(GameObject* parent);

    //�f�X�g���N�^
    ~Obstacle();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
