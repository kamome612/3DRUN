#pragma once
#include "Engine/GameObject.h"
//�X�e�[�W�̂������
class Stage :
    public GameObject
{
    double timer_;
    double rTimer_;
public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

