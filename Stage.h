#pragma once
#include "Engine/GameObject.h"
#include "array"
//#include "CDTIMER.h"

//�X�e�[�W�̂������
class Stage :
    public GameObject
{
    /*CDTIMER rTimer_;
    CDTIMER oTimer_;
    CDTIMER osTimer_;*/
    double DEC_TIMER = 1.0 / 60.0;
    double rTimer_;
    double oTimer_;
    double osTimer_;
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

