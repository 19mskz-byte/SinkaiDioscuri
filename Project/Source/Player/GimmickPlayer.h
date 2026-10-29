#pragma once
#include <DxLib.h>
#include "PlayerParameter.h"
#include "../Map/MapParameter.h"
#include "../Collision/Collision.h"

// プレイヤーサイズ
#define GIMMICK_PLAYER_WIDTH	(80.0f)
#define GIMMICK_PLAYER_HEIGHT	(80.0f)
#define GIMMICK_PLAYER_RADIUS	(40.0f)

// 関数のプロトタイプ宣言
void InitGimmickPlayer();
void LoadGimmickPlayer();
void StartGimmickPlayer();
void StepGimmickPlayer();
void UpdateGimmickPlayer();
void DrawGimmickPlayer();
void FinGimmickPlayer();

// 取得関数
GimmickPlayerData* GetGimmickPlayer();

// 当たり判定
void GimmickPlayerHitNormalBlock(MapChipData mapChipData);