#pragma once
#include "Engine/GameObject.h"
//��Q��(�p�b�N�}��)
class Obstacle :
    public GameObject
{
    int hObs_;
    double timer_;
    float speed_;
public:
    //�R���X�g���N�^
    Obstacle(GameObject* parent);
    //�R���X�g���N�^(x���W�t)
    Obstacle(GameObject* parent,int x_ ,float s_);

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

