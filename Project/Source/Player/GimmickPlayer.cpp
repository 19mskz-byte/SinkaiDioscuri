#include <DxLib.h>
#include "GimmickPlayer.h"
#include "../Animation/Animation.h"
#include "../Input/Input.h"
#include "../Map/MapChip.h"
#include "../Map/MapManager.h"
#include "../Camera/Camera.h"

struct  PlayerAnimationParam
{
	int interval;
	int frameNum;
	int width;
	int height;
};

const PlayerAnimationParam GIMMICK_PLAYER_ANIM_PARAM[GIMMICK_PLAYER_ANIM_MAX] =
{
	8,7,80,80,
	5,8,80,80,
	8,2,80,80,
	8,2,80,80,
	8,1,80,80,
};

//プレイヤー設定
#define GIMMICK_PLAYER_DEFAULT_POS_X (300.0f)
#define GIMMICK_PLAYER_DEFAULT_POS_Y (600.0f)
#define GIMMICK_PLAYER_MOVESPEED (4.0f)

//ジャンプ力
#define GIMMICK_PLAYER_JUMP_POWER (12.0f)

//重力
#define GIMMICK_PLAYER_GRAVITY (0.4f)

//マップ衝突判定用のプレイヤーサイズ補正
#define GIMMICK_PLAYER_MAP_COLLISION_OFFSET (0.1f)

//判定サイズ
// 矩形判定の位置補正
#define GIMMICK_PLAYER_BOX_COLLISION_OFFSET_X (24)
#define GIMMICK_PLAYER_BOX_COLLISION_OFFSET_Y (20)
#define GIMMICK_PLAYER_BOX_COLLISION_WIDTH (40.0f)
#define GIMMICK_PLAYER_BOX_COLLISION_HEIGHT (80.0f)

#define GIMMICK_PLAYER_CHECK_ROUDND_NUM (2)

GimmickPlayerData g_PlayerData = { 0 };
GimmickPlayerData g_PrevPlayerData = { 0 };

void StartGimmickPlayerAnimation(GimmickPlayerAnimationType anim);
void UpdateGimmickPlayerAnimation();
void GimmickPlayerCalcBoxCollision(GimmickPlayerData player, float& x, float& y, float& w, float& h);

void InitGimmickPlayer()
{
	//構造体はmemsetで0初期化できる
	memset(&g_PlayerData.body, 0, sizeof(g_PlayerData.body));
	g_PlayerData.active = false;
	g_PlayerData.playAnim = GIMMICK_PLAYER_ANIM_NONE;
	g_PlayerData.body.isAir = false;

	for (int i = 0; i < GIMMICK_PLAYER_ANIM_MAX; i++)
	{
		g_PlayerData.animation[i] = new AnimationData;
		InitAnimation(g_PlayerData.animation[i]);
	}
}

void LoadGimmickPlayer()
{
	g_PlayerData.animation[GIMMICK_PLAYER_ANIM_IDLE]->handle = LoadGraph("Data/Player/GimmickPlayerIdle.png");
}

void StartGimmickPlayer()
{
	g_PlayerData.active = true;
	g_PlayerData.body.pos.x = GIMMICK_PLAYER_DEFAULT_POS_X;
	g_PlayerData.body.pos.y = GIMMICK_PLAYER_DEFAULT_POS_Y;
	g_PlayerData.body.width = GIMMICK_PLAYER_WIDTH;
	g_PlayerData.body.height =GIMMICK_PLAYER_HEIGHT;

	g_PlayerData.bodycollision.pos.x = GIMMICK_PLAYER_BOX_COLLISION_OFFSET_X;
	g_PlayerData.bodycollision.pos.y = GIMMICK_PLAYER_BOX_COLLISION_OFFSET_Y;
	g_PlayerData.bodycollision.width = GIMMICK_PLAYER_BOX_COLLISION_WIDTH;
	g_PlayerData.bodycollision.height = GIMMICK_PLAYER_BOX_COLLISION_HEIGHT;

	StartGimmickPlayerAnimation(GIMMICK_PLAYER_ANIM_IDLE);
}

void StepGimmickPlayer()
{
	if (!g_PlayerData.active)
	{
		return;
	}

	g_PrevPlayerData = g_PlayerData;

	g_PlayerData.body.move.x = 0.0f;

	g_PlayerData.body.move.y += GIMMICK_PLAYER_GRAVITY;

	if (IsInputKey(KEY_I))
	{
		g_PlayerData.body.move.y = GIMMICK_PLAYER_JUMP_POWER;
	}
	if (IsInputKey(KEY_J))
	{
		g_PlayerData.body.move.x = -GIMMICK_PLAYER_MOVESPEED;
		g_PlayerData.isTurn = true;
	}
	if (IsInputKey(KEY_K))
	{

	}
	if (IsInputKey(KEY_L))
	{
		g_PlayerData.body.move.x = GIMMICK_PLAYER_MOVESPEED;
		g_PlayerData.isTurn = false;
	}
	if (IsInputKey(KEY_H))
	{

	}
	if (IsInputKey(KEY_U))
	{

	}
}

void UpdateGimmickPlayer()
{
	if (!g_PlayerData.active)return;

	if (g_PlayerData.body.move.y<0.0f || g_PlayerData.body.move.y>GIMMICK_PLAYER_GRAVITY)
	{
		g_PlayerData.body.isAir = true;
	}

	g_PlayerData.body.pos.x += g_PlayerData.body.move.x;
	g_PlayerData.body.pos.y += g_PlayerData.body.move.y;

	// 当たり判定付きで移動
	MoveWithCollision(&g_PlayerData.body);

	DrawFormatString(0, 13, GetColor(255, 255, 255), "プレイヤーの座標＝[%f, %f]", g_PlayerData.body.pos.x, g_PlayerData.body.pos.y);

	UpdateGimmickPlayerAnimation();
}

void DrawGimmickPlayer()
{
	if (!g_PlayerData.active)return;

	int playerX = (int)(g_PlayerData.body.pos.x + 0.5f);
	int	playerY = (int)(g_PlayerData.body.pos.y + 0.5f);

	GimmickPlayerData temp = g_PlayerData;
	CameraData camera = GetCamera();

	temp.body.pos.y = g_PlayerData.body.pos.y - camera.pos.y;
	
	// アニメーション描画でプレイヤーを描画する
	GimmickPlayerAnimationType animType = g_PlayerData.playAnim;
	AnimationData* animData = g_PlayerData.animation[animType];
	DrawAnimation(animData, playerX, playerY, g_PlayerData.isTurn);
	
	// 当たり判定描画
	float x, y, w, h;
	GimmickPlayerCalcBoxCollision(temp, x, y, w, h);
	DrawBox((int)x, (int)y, (int)(x + w), (int)(y + h), GetColor(255, 255, 255), false);
}

void FinGimmickPlayer()
{
	for (int i = 0; i < GIMMICK_PLAYER_ANIM_MAX; i++)
	{
		DeleteGraph(g_PlayerData.animation[i]->handle);
	}
}

GimmickPlayerData* GetGimmickPlayer()
{
	return &g_PlayerData;
}


void StartGimmickPlayerAnimation(GimmickPlayerAnimationType anim)
{
	// 再生中のアニメーションであれば何もしない
	if (anim == g_PlayerData.playAnim) return;

	// 再生中アニメーション設定
	g_PlayerData.playAnim = anim;

	// 再生に必要なデータを取得
	AnimationData* animData = g_PlayerData.animation[anim];
	PlayerAnimationParam animParam = GIMMICK_PLAYER_ANIM_PARAM[anim];

	// アニメーション再生
	StartAnimation(animData, g_PlayerData.body.pos.x, g_PlayerData.body.pos.y, animParam.interval, animParam.frameNum, animParam.width, animParam.height, true);

}

void UpdateGimmickPlayerAnimation()
{
	// 地上にいるか
	if (!g_PlayerData.body.isAir)
	{
		// 横に移動していれば走っている
		if (g_PlayerData.body.move.x < 0.0f || g_PlayerData.body.move.y > 0.0f)
		{
			// 走るアニメーション
			StartGimmickPlayerAnimation(GIMMICK_PLAYER_ANIM_RUN);
		}
		else
		{
			// 移動していなければ待機
			StartGimmickPlayerAnimation(GIMMICK_PLAYER_ANIM_IDLE);
		}
	}
	// 空中にいる
	else
	{
		// 上昇していればジャンプアニメーション
		if (g_PlayerData.body.move.y < 0.0f)
		{
			StartGimmickPlayerAnimation(GIMMICK_PLAYER_ANIM_JUMP);
		}
		// 下降していれば落下アニメーション
		else if (g_PlayerData.body.move.y > 0.0f)
		{
			StartGimmickPlayerAnimation(GIMMICK_PLAYER_ANIM_FALL);
		}
	}

	// アニメーション更新
	GimmickPlayerAnimationType animType = g_PlayerData.playAnim;
	AnimationData* animData = g_PlayerData.animation[animType];
	UpdateAnimation(animData);
}

void GimmickPlayerCalcBoxCollision(GimmickPlayerData player, float& x, float& y, float& w, float& h)
{
	x = player.isTurn ?
		player.body.pos.x + GIMMICK_PLAYER_WIDTH - player.bodycollision.pos.x - player.bodycollision.width :
		player.body.pos.x + player.bodycollision.pos.x;
	y = player.body.pos.y+player.bodycollision.pos.y;
	w = player.bodycollision.width;
	h = player.bodycollision.height;
}
