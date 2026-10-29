#include"Dxlib.h"
#include "Scene/SceneManager.h"
#include "GameSetting/GameSetting.h"

//プログラムはWinMainから始まります
int WINAPI WinMain(_In_ HINSTANCE hInstanse, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// ウィンドウモードON
	ChangeWindowMode(TRUE);

	// 画面解像度の設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_DEPTH);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ウィンドウサイズ設定
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	// 透過色の設定
	SetTransColor(TRANS_COLOR_R, TRANS_COLOR_G, TRANS_COLOR_B);

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);


	//ゲームのメインループ
	while(ProcessMessage() >= 0)
	{
		//画面をクリア
		ClearDrawScreen();

		SceneManagerUpdate();

		//エスケープキーで終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;

		//画面をフリップ
		ScreenFlip();
	}

	//DXライブラリ仕様の終了処理
	DxLib_End();

	//ソフトの終了
	return 0;
}
