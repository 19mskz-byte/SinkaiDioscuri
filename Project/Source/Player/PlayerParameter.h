#pragma once
#include <DxLib.h>
#include "../Collision/Collision.h"
#include "../Animation/Animation.h"

// プレイヤーデータ
struct PlayerData
{
	bool active;								// 生存フラグ
	bool isTurn;								// 左を向いているか
	bool isAir;									// 空中にいるか
	VECTOR pos;									// 座標
	float moveX;								// X移動量
	float moveY;								// Y移動量
	//AnimationData animation[PLAYER_ANIM_MAX];	// アニメーション
	//PlayerAnimationType playAnim;				// 再生中のアニメーション
	BodyCollision bodycollision;			    // 矩形当たり判定
};
