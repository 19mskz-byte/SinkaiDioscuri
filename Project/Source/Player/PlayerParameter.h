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
	POWERFUL_PLAYER_ANIM_LANDING,
	POWERFUL_PLAYER_ANIM_MAX,
	POWERFUL_PLAYER_ANIM_NONE = -1
};

enum GimmickPlayerAnimationType
{
	GIMMICK_PLAYER_ANIM_IDLE,
	GIMMICK_PLAYER_ANIM_RUN,
	GIMMICK_PLAYER_ANIM_JUMP,
	GIMMICK_PLAYER_ANIM_FALL,
	GIMMICK_PLAYER_ANIM_LANDING,
	GIMMICK_PLAYER_ANIM_MAX,
	GIMMICK_PLAYER_ANIM_NONE = -1
};


// プレイヤーデータ
struct PowerfulPlayerData
{
	bool active;								// 生存フラグ
	bool isTurn;								// 左を向いているか
	bool isAir;									// 空中にいるか
	VECTOR pos;									// 座標
	float moveX;								// X移動量
	float moveY;								// Y移動量
	AnimationData* animation[POWERFUL_PLAYER_ANIM_MAX];	// アニメーション
	PowerfulPlayerAnimationType playAnim;				// 再生中のアニメーション
	BodyCollision bodycollision;			    // 矩形当たり判定
};

struct GimmickPlayerData
{
	bool active;								// 生存フラグ
	bool isTurn;								// 左を向いているか
	bool isAir;									// 空中にいるか
	VECTOR pos;									// 座標
	float moveX;								// X移動量
	float moveY;								// Y移動量
	AnimationData* animation[GIMMICK_PLAYER_ANIM_MAX];	// アニメーション
	GimmickPlayerAnimationType playAnim;				// 再生中のアニメーション
	BodyCollision bodycollision;			    // 矩形当たり判定
};
