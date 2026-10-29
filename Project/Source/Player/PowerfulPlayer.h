#pragma once
#include <DxLib.h>
#include "../Map/MapParameter.h"
#include "PlayerParameter.h"
#include "../Collision/Collision.h"

// プレイヤーサイズ
#define POWERFUL_PLAYER_WIDTH	(80.0f)
#define POWERFUL_PLAYER_HEIGHT	(80.0f)
#define POWERFUL_PLAYER_RADIUS	(40.0f)

// 関数のプロトタイプ宣言
void InitPowerfulPlayer();
void LoadPowerfulPlayer();
void StartPowerfulPlayer();
void StepPowerfulPlayer();
void UpdatePowerfulPlayer();
void DrawPowerfulPlayer();
void FinPowerfulPlayer();

// 取得関数
PowerfulPlayerData* GetPowerfulPlayer();

// 当たり判定
void PowerfulPlayerHitNormalBlock(MapChipData mapChipData);