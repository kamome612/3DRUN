#pragma once
#include "Engine/GameObject.h"
class test :
    public GameObject
{
    int hModel_;
public:
    //�R���X�g���N�^
    test(GameObject* parent);

    test(GameObject* parent, int z_);

    //�f�X�g���N�^
    ~test();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

