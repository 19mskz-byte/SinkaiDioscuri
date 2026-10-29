#pragma once
#include <DxLib.h>
#include "../Map/MapParameter.h"
#include "PlayerParameter.h"
#include "../Collision/Collision.h"

// プレイヤーサイズ
#define POWERFUL_PLAYER_WIDTH	(72.0f)
#define POWERFUL_PLAYER_HEIGHT	(72.0f)
#define POWERFUL_PLAYER_RADIUS	(36.0f)

//// アニメーションタイプ
//enum PowerfulPlayerAnimationType
//{
//	POWERFUL_PLAYER_ANIM_IDLE,
//	POWERFUL_PLAYER_ANIM_RUN,
//	POWERFUL_PLAYER_ANIM_JUMP,
//	POWERFUL_PLAYER_ANIM_FALL,
//	POWERFUL_PLAYER_ANIM_LANDING,
//	POWERFUL_PLAYER_ANIM_MAX,
//	POWERFUL_PLAYER_ANIM_NONE = -1
//};

// 関数のプロトタイプ宣言
void InitPowerfulPlayer();
void LoadPowerfulPlayer();
void StartPowerfulPlayer();
void StepPowerfulPlayer();
void UpdatePowerfulPlayer();
void DrawPowerfulPlayer();
void FinPowerfulPlayer();

// 取得関数
PlayerData GetPowerfulPlayer();

// 当たり判定
void PowerfulPlayerHitNormalBlock(MapChipData mapChipData);