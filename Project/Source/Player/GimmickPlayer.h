#pragma once
#include <DxLib.h>
#include "PlayerParameter.h"
#include "../Map/MapParameter.h"
#include "../Collision/Collision.h"

// プレイヤーサイズ
#define GIMMICK_PLAYER_WIDTH	(72.0f)
#define GIMMICK_PLAYER_HEIGHT	(72.0f)
#define GIMMICK_PLAYER_RADIUS	(36.0f)

//// アニメーションタイプ
//enum GimmickPlayerAnimationType
//{
//	GIMMICK_PLAYER_ANIM_IDLE,
//	GIMMICK_PLAYER_ANIM_RUN,
//	GIMMICK_PLAYER_ANIM_JUMP,
//	GIMMICK_PLAYER_ANIM_FALL,
//	GIMMICK_PLAYER_ANIM_LANDING,
//	GIMMICK_PLAYER_ANIM_MAX,
//	GIMMICK_PLAYER_ANIM_NONE = -1
//};

// 関数のプロトタイプ宣言
void InitGimmickPlayer();
void LoadGimmickPlayer();
void StartGimmickPlayer();
void StepGimmickPlayer();
void UpdateGimmickPlayer();
void DrawGimmickPlayer();
void FinGimmickPlayer();

// 取得関数
PlayerData GetGimmickPlayer();

// 当たり判定
void GimmickPlayerHitNormalBlock(MapChipData mapChipData);