#include <DxLib.h>
#include "GimmickPlayer.h"
#include "../Animation/Animation.h"
#include "../Input/Input.h"
#include "../Map/MapChip.h"

//struct  PlayerAnimationParam
//{
//	int interval;
//	int frameNum;
//	int width;
//	int height;
//};

//const PlayerAnimationParam GIMMICK_PLAYER_ANIM_PARAM[PLAYER_ANIM_MAX] =
//{
//	8,4,72,72,
//	5,8,72,72,
//	8,2,72,72,
//	8,2,72,72,
//	8,1,72,72,
//};

//プレイヤー設定
#define GIMMICK_PLAYER_DEFAULT_POS_X (100.0f)
#define GIMMICK_PLAYER_DEFAULT_POS_Y (600.0f)
#define GIMMICK_PLAYER_MOVESPEED (4.0f)

//ジャンプ力
#define GIMMICK_PLAYER_JUMP_POWER (12.0f)

//重力
#define GIMMICK_PLAYER_GRAVITY (0.4f)

//マップ衝突判定用のプレイヤーサイズ補正
#define GIMMICK_PLAYER_MAP_COLLISION_OFFSET (0.1f)

//矩形判定の位置補正
#define GIMMICK_PLAYER_BOX_COLLISION_OFFSET_X (24.0f)
#define GIMMICK_PLAYER_BOX_COLLISION_OFFSET_Y (44.0f)

//判定サイズ
#define GIMMICK_PLAYER_BOX_COLLISION_WIDTH (20.0f)
#define GIMMICK_PLAYER_BOX_COLLISION_HEIGHT (44.0f)

PlayerData g_PlayerData = { 0 };
PlayerData g_PrevPlayerData = { 0 };

void GimmickPlayerCalcBoxCollision(PlayerData player, float& x, float& y, float& w, float& h);

void InitGimmickPlayer()
{
	g_PlayerData.pos.x = GIMMICK_PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = GIMMICK_PLAYER_DEFAULT_POS_Y;
	g_PlayerData.moveX = 0.0f;
	g_PlayerData.moveY = 0.0f;
	g_PlayerData.active = false;
	/*g_PlayerData.playAnim = GIMMICK_PLAYER_ANIM_NONE;*/

	/*for (int i = 0; i < GIMMICK_PALYER_ANIM_MAX; i++)
	{
		InitAnimation(&g_PlayerData.animation[i]);
	}*/

	//構造体はmemsetで0初期化できる
	memset(&g_PlayerData.bodycollision, 0, sizeof(g_PlayerData.bodycollision));
}

void LoadGimmickPlayer()
{

}

void StartGimmickPlayer()
{
	g_PlayerData.active = true;

	g_PlayerData.bodycollision.pos.x = GIMMICK_PLAYER_BOX_COLLISION_OFFSET_X;
	g_PlayerData.bodycollision.pos.y = GIMMICK_PLAYER_BOX_COLLISION_OFFSET_Y;
	g_PlayerData.bodycollision.width = GIMMICK_PLAYER_BOX_COLLISION_WIDTH;
	g_PlayerData.bodycollision.height =GIMMICK_PLAYER_HEIGHT;

	/*StartPlayerAnimation(GIMMICK_PLAYER_ANIM_IDLE);*/
}

void StepGimmickPlayer()
{
	if (!g_PlayerData.active)
	{
		return;
	}

	g_PrevPlayerData = g_PlayerData;

	g_PlayerData.moveX = 0.0f;

	g_PlayerData.moveY += GIMMICK_PLAYER_GRAVITY;

	if (IsInputKey(KEY_I))
	{
		g_PlayerData.moveY -= GIMMICK_PLAYER_JUMP_POWER;
	}
	if (IsInputKey(KEY_J))
	{
		g_PlayerData.moveX = -GIMMICK_PLAYER_MOVESPEED;
		g_PlayerData.isTurn = true;
	}
	if (IsInputKey(KEY_K))
	{

	}
	if (IsInputKey(KEY_L))
	{
		g_PlayerData.moveX = GIMMICK_PLAYER_MOVESPEED;
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

	if (g_PlayerData.moveY<0.0f || g_PlayerData.moveY>GIMMICK_PLAYER_GRAVITY)
	{
		g_PlayerData.isAir = true;
	}

	g_PlayerData.pos.x += g_PlayerData.moveX;
	g_PlayerData.pos.y += g_PlayerData.moveY;

	/*UpdatePlayerAnimation();*/
}

void DrawGimmickPlayer()
{
	if (!g_PlayerData.active)return;

	// 当たり判定描画
	float x, y, w, h;
	GimmickPlayerCalcBoxCollision(g_PlayerData, x, y, w, h);
	DrawBox((int)x, (int)y, (int)(x + w), (int)(y + h), GetColor(255, 255, 255), false);
}

void FinGimmickPlayer()
{
	/*for (int i = 0; i < GIMMICK_PLAYER_ANIM_MAX; i++)
	{
		DeleteGraph(g_PlayerData.animation[i].handle);
	}*/
}

PlayerData GetGimmickPlayer()
{
	return g_PlayerData;
}

void GimmickPlayerHitNormalBlock(MapChipData mapChipData)
{
	PlayerData player = g_PlayerData;
	BlockData* block = mapChipData.data;
	const float POS_OFFSET = GIMMICK_PLAYER_MAP_COLLISION_OFFSET;
	const float SIZE_OFFSET = GIMMICK_PLAYER_MAP_COLLISION_OFFSET * 2;

	// ターンフラグは前回のものにしないと反転した分ずれる
	player.isTurn = g_PrevPlayerData.isTurn;

	// Y移動を戻し、横に当たっているかチェック
	player.pos.x = g_PlayerData.pos.x;
	player.pos.y = g_PrevPlayerData.pos.y;

	// 当たり判定のボックス計算
	float x, y, w, h;
	GimmickPlayerCalcBoxCollision(player, x, y, w, h);

	if (CheckSquareSquare(x + POS_OFFSET, y + POS_OFFSET, w - SIZE_OFFSET, h - SIZE_OFFSET,
		block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
	{
		// 左からあたったか
		if (player.moveX > 0.0f)
		{
			// 左に押し出す
			g_PlayerData.pos.x -= (x + w) - block->pos.x;
		}
		// 右からあたったか
		else if (player.moveX < 0.0f)
		{
			// 右に押し出す
			g_PlayerData.pos.x += (block->pos.x + MAP_CHIP_WIDTH) - x;
		}
	}

	// X移動を戻し、縦に当たっているかチェック
	player.pos.x = g_PrevPlayerData.pos.x;
	player.pos.y = g_PlayerData.pos.y;

	// 当たり判定のボックス計算
	GimmickPlayerCalcBoxCollision(player, x, y, w, h);

	// まだ当たっているなら縦に当たっている
	if (CheckSquareSquare(x + POS_OFFSET, y + POS_OFFSET, w - SIZE_OFFSET, h - SIZE_OFFSET,
		block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
	{
		// Y移動量を0にする
		g_PlayerData.moveY = 0.0f;

		// 上からあたったか
		if (player.moveY > 0.0f)
		{
			// 上に押し出す
			g_PlayerData.pos.y -= (y + h) - block->pos.y;
			g_PlayerData.isAir = false;
		}
		// 下からあたったか
		else if (player.moveY < 0.0f)
		{
			// 下に押し出す
			g_PlayerData.pos.y += (block->pos.y + MAP_CHIP_WIDTH) - y;
		}
	}
}

void GimmickPlayerCalcBoxCollision(PlayerData player, float& x, float& y, float& w, float& h)
{
	x = player.isTurn ?
		player.pos.x + GIMMICK_PLAYER_WIDTH - player.bodycollision.pos.x - player.bodycollision.width :
		player.pos.x + player.bodycollision.pos.x;
	y = player.pos.y + player.bodycollision.pos.y;
	w = player.bodycollision.width;
	h = player.bodycollision.height;
}
