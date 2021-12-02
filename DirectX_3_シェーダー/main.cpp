// Include
#include "DxLib.h"

// WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow)
{
    ChangeWindowMode(true);   // �E�B���h�E���[�h�ɐݒ�

    // DX���C�u�����̏�����
    if (DxLib_Init() == -1) return 0;

    // ����ʂɕ`�悷��
    SetDrawScreen(DX_SCREEN_BACK);

    // �e�N�X�`���̓ǂݍ���
    int texture = LoadGraph("your name.png");

    // ���_�f�[�^�̍쐬
    VERTEX3DSHADER v3s[ 6 ] = { 0 };
    v3s[0].pos = VGet( -0.5F,  0.5F,  0.0F);
    v3s[1].pos = VGet(  0.5F,  -0.5F, 0.0F);
    v3s[2].pos = VGet( -0.5F,  -0.5F, 0.0F);
    v3s[0].dif = GetColorU8(255, 0, 0, 255);
    v3s[1].dif = GetColorU8(0, 255, 0, 255);
    v3s[2].dif = GetColorU8(0, 0, 255, 255);
    v3s[0].u = 0.0F; v3s[0].v = 0.0F;
    v3s[1].u = 0.0F; v3s[1].v = 1.0F;
    v3s[2].u = 1.0F; v3s[2].v = 1.0F;

    v3s[3].pos = VGet(-0.5F, 0.5F, 0.0F);
    v3s[4].pos = VGet(0.5F, -0.5F, 0.0F);
    v3s[5].pos = VGet(0.5F, 0.5F, 0.0F);
    v3s[3].dif = GetColorU8(255, 0, 0, 255);
    v3s[4].dif = GetColorU8(0, 255, 0, 255);
    v3s[5].dif = GetColorU8(0, 0, 255, 255);
    v3s[3].u = 0.0F; v3s[3].v = 0.0F;
    v3s[4].u = 1.0F; v3s[4].v = 1.0F;
    v3s[5].u = 0.0F; v3s[5].v = 1.0F;

    // ���_�V�F�[�_�̓ǂݍ���
    int vs = LoadVertexShader("vs.cso");

    // �s�N�Z���V�F�[�_�̓ǂݍ���
    int ps = LoadPixelShader("ps.cso");

    // �e�N�X�`���̐ݒ�
    SetUseTextureToShader(0, texture);

    // ���_�V�F�[�_�ƃs�N�Z���V�F�[�_��ݒ�
    SetUseVertexShader(vs);
    SetUsePixelShader(ps);

    // ���C�����[�v
    while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
    {
        // ��ʏ�����
        ClearDrawScreen();

        // �V�F�[�_���g���ĕ`��
        DrawPolygon3DToShader(v3s, 2);

        ScreenFlip(); // ����ʂɕ`�悵�����e��\�ɕ\������
    }

    // �V�F�[�_�̔j��
    DeleteShader(vs);
    DeleteShader(ps);

    // �e�N�X�`���̔j��
    DeleteGraph(texture);

    // DX���C�u�����̔j��
    DxLib_End();

    return 0;
}