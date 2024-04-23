#pragma once
#include "Engine/GameObject.h"
#include "array"

//�X�e�[�W�̂������
class Stage :
    public GameObject
{
    double timer_;
    double rTimer_;
    float speed_;
    std::array<int, 3>xa = { -2,0,2 };
    
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

