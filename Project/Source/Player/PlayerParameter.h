#pragma once
#include <DxLib.h>
#include "../Collision/Collision.h"
#include "../Animation/Animation.h"


// アニメーションタイプ
enum PowerfulPlayerAnimationType
{
	POWERFUL_PLAYER_ANIM_IDLE,
	POWERFUL_PLAYER_ANIM_RUN,
	POWERFUL_PLAYER_ANIM_JUMP,
	POWERFUL_PLAYER_ANIM_FALL,
	POWERFUL_PLAYER_ANIM_MAX,
	POWERFUL_PLAYER_ANIM_NONE = -1
};

//アニメーションの状態
enum GimmickPlayerAnimationType
{
	GIMMICK_PLAYER_ANIM_IDLE,
	GIMMICK_PLAYER_ANIM_RUN,
	GIMMICK_PLAYER_ANIM_JUMP,
	GIMMICK_PLAYER_ANIM_FALL,
	GIMMICK_PLAYER_ANIM_MAX,
	GIMMICK_PLAYER_ANIM_NONE = -1
};

//持っている物の種類
enum PlayerAmontType
{
	PLAYER_AMOUNT_NONE=-1,
	PLAYER_AMOUNT_WOODBLOCK,
	PLAYER_AMOUNT_MAX,
};

//持っている物の状態
enum PlayerAmontState
{
	PLAYER_AMOUNT_STATE_NONE=-1,
	PLAYER_AMOUNT_STATE_IDLE,
	PLAYER_AMOUNT_STATE_THROW,
	PLAYER_AMOUNT_STATE_PUT,
	PLAYER_AMOUNT_STATE_MAX,
};

// プレイヤーデータ
struct PowerfulPlayerData
{								
	bool active;										// 生存フラグ
	bool isTurn;										// 左を向いているか
	AnimationData* animation[POWERFUL_PLAYER_ANIM_MAX];	// アニメーション
	PowerfulPlayerAnimationType playAnim;				// 再生中のアニメーション
	Body body;											//	本体の当たり判定
	BodyCollision bodycollision;						//	矩形の当たり判定
	PlayerAmontType playerAmontType;					// プレイヤーが持っている物の種類
	PlayerAmontState playerAmontState;					// プレイヤーが持っている物の状態
};

struct GimmickPlayerData
{
	bool active;										// 生存フラグ
	bool isTurn;										// 左を向いているか
	AnimationData* animation[GIMMICK_PLAYER_ANIM_MAX];	// アニメーション
	GimmickPlayerAnimationType playAnim;				// 再生中のアニメーション
	Body body;											//	本体の当たり判定
	BodyCollision bodycollision;						//	矩形の当たり判定
	PlayerAmontType playerAmontType;					// プレイヤーが持っている物の種類
	PlayerAmontState playerAmontState;					// プレイヤーが持っている物の状態
};
