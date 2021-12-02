// Include
#include "DxLib.h"

// WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow)
{
    ChangeWindowMode(true);   // ウィンドウモードに設定

    // DXライブラリの初期化
    if (DxLib_Init() == -1) return 0;

    // 裏画面に描画する
    SetDrawScreen(DX_SCREEN_BACK);

    // テクスチャの読み込み
    int texture = LoadGraph("your name.png");

    // 頂点データの作成
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

    // 頂点シェーダの読み込み
    int vs = LoadVertexShader("vs.cso");

    // ピクセルシェーダの読み込み
    int ps = LoadPixelShader("ps.cso");

    // テクスチャの設定
    SetUseTextureToShader(0, texture);

    // 頂点シェーダとピクセルシェーダを設定
    SetUseVertexShader(vs);
    SetUsePixelShader(ps);

    // メインループ
    while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
    {
        // 画面初期化
        ClearDrawScreen();

        // シェーダを使って描画
        DrawPolygon3DToShader(v3s, 2);

        ScreenFlip(); // 裏画面に描画した内容を表に表示する
    }

    // シェーダの破棄
    DeleteShader(vs);
    DeleteShader(ps);

    // テクスチャの破棄
    DeleteGraph(texture);

    // DXライブラリの破棄
    DxLib_End();

    return 0;
}