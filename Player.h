#pragma once
#include "Engine/GameObject.h"
//�v���C���[
class Player :
    public GameObject
{
    int hPlayer_;
    double timer_;
public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����蔻��
    void OnCollision(GameObject* pTarget) override;
};

