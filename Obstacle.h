#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//��Q��(�p�b�N�}��)
class Obstacle :
    public GameObject
{
    Text* pText_;
    int hObs_;
    float speed_;
public:
    //�R���X�g���N�^
    Obstacle(GameObject* parent);
    //x���W��speed�t��
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

