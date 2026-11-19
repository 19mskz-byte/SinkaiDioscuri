#include "DxLib.h"
#include "Collision.h"
#include "../Player/PowerfulPlayer.h"
#include "../Player/GimmickPlayer.h"
#include "../Map/Block.h"
#include "../Map//MapManager.h"
#include "../Map/MapChip.h"
#include <math.h>

// 矩形と点の当たり判定
// 引数
// squarePosX:矩形の左上X座標
// squarePosY:矩形の左上Y座標
// squareWidth:矩形の横幅
// squareHeight:矩形の高さ
// pointX:点のX座標
// pointY:点のY座標
// 戻り値
// 当たっていればtrue
bool CheckSquarePoint(float squarePosX, float squarePosY, float squareWidth, float squareHeight, float pointX, float pointY)
{
	// 点のX座標が矩形の間にあるか
	if (pointX >= squarePosX && pointX <= (squarePosX + squareWidth))
	{
		// 点のY座標が矩形の間にあるか
		if (pointY >= squarePosY && (pointY <= squarePosY + squareHeight))
		{
			// 当たっている
			return true;
		}
	}

	return false;
}

// 矩形と矩形の当たり判定
// 引数
// squareA_PosX:矩形Aの左上X座標
// squareA_PosY:矩形Aの左上Y座標
// squareA_Width:矩形Aの横幅
// squareA_Height:矩形Aの高さ
// squareB_PosX:矩形Bの左上X座標
// squareB_PosY:矩形Bの左上Y座標
// squareB_Width:矩形Bの横幅
// squareB_Height:矩形Bの高さ
// 戻り値
// 当たっていればtrue
bool CheckSquareSquare(float squareA_PosX, float squareA_PosY, float squareA_Width, float squareA_Height, float squareB_PosX, float squareB_PosY, float squareB_Width, float squareB_Height)
{
	// 矩形Aの各辺の位置を計算する
	float leftA = squareA_PosX;
	float rightA = squareA_PosX + squareA_Width; 
	float topA = squareA_PosY;
	float bottomA = squareA_PosY + squareA_Height;

	// 矩形Bの各辺の位置を計算する
	float leftB = squareB_PosX;
	float rightB = squareB_PosX + squareB_Width;
	float topB = squareB_PosY;
	float bottomB = squareB_PosY + squareB_Height;

	// 左右の辺がめり込んでいるかチェック
	if (rightA > leftB && leftA < rightB)
	{
		// 上下の片がめり込んでいるかチェック
		if (bottomA > topB && topA < bottomB)
		{
			// 当たっている
			return true;
		}
	}

	return false;
}

// 円と点の当たり判定
// 引数
// circlePosX:円の中心座標（X）
// circlePosY:円の中心座用（Y）
// circleRadius:円の半径
// pointX:点のX座標
// pointY:点のY座標
// 戻り値
// 当たっていればtrue
bool CheckCirclePoint(float circlePosX, float circlePosY, float circleRadius, float pointX, float pointY)
{
	// 円の中心から点までの距離を計算する
	float distance = sqrtf((pointX - circlePosX) * (pointX - circlePosX) + (pointY - circlePosY) * (pointY - circlePosY));

	// 求めた距離が半径の長さ以下であれば当たっている
	if (distance <= circleRadius)
	{
		return true;
	}

	return false;
}

// 円と点の当たり判定
// 引数
// circleA_PosX:円Aの中心座標（X）
// circleA_PosY:円Aの中心座用（Y）
// circleA_Radius:円Aの半径
// circleB_PosX:円Bの中心座標（X）
// circleB_PosX:円Bの中心座用（Y）
// circleB_Radius:円Bの半径
// 戻り値
// 当たっていればtrue
bool CheckCircleCircle(float circleA_PosX, float circleA_PosY, float circleA_Radius, float circleB_PosX, float circleB_PosY, float circleB_Radius)
{
	// 円の中心間の距離を計算する
	float distance = sqrtf((circleB_PosX - circleA_PosX) * (circleB_PosX - circleA_PosX) + (circleB_PosY - circleA_PosY) * (circleB_PosY - circleA_PosY));

	// 中心間の距離が2つの円の半径の合計以下であれば当たっている
	if (distance <= (circleA_Radius + circleB_Radius))
	{
		return true;
	}

	return false;
}

void MoveWithCollision(Body* body, BodyCollision* bodycollision)
{
	float prevPosY = body->pos.y - body->move.y;

	body->feetState = PLAYER_FEET_STATE_AIR;

	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			MapChipData mapChipData = GetMapChipData(x, y);
			if (mapChipData.mapChip == 0)continue;

			BlockData* block = mapChipData.data;
			if (CheckSquareSquare(body->pos.x + bodycollision->pos.x, prevPosY + bodycollision->pos.y, bodycollision->width, bodycollision->height,
				block->pos.x, block->pos.y, block->width, block->height))
			{
				//右からあたる
				if (body->move.x > 0.0f)
				{
					body->pos.x = block->pos.x - bodycollision->width - bodycollision->pos.x;
				}

				//左からあたる
				else if (body->move.x < 0.0f)
				{
					body->pos.x = block->pos.x + block->width - bodycollision->pos.x;
				}

				body->move.x = 0.0f;
			}
		}
	}

	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			MapChipData mapChipData = GetMapChipData(x, y);
			if (mapChipData.mapChip == 0)continue;

			BlockData* block = mapChipData.data;
			if (CheckSquareSquare(body->pos.x + bodycollision->pos.x, body->pos.y + bodycollision->pos.y, bodycollision->width, bodycollision->height,
				block->pos.x, block->pos.y, block->width, block->height))
			{
				//上からあたる
				if (body->move.y > 0.0f)
				{
					body->pos.y = block->pos.y - bodycollision->height - bodycollision->pos.y;
					body->feetState = PLAYER_FEET_STATE_BLOCK;
				}

				//下からあたる
				else if (body->move.y < 0.0f)
				{
					body->pos.y = block->pos.y + block->height - bodycollision->pos.y;
				}

				body->move.y = 0;
			}
		}
	}
}

void WoodBlockHitMapBlock(WoodBlock* woodBlock)
{
	float prevPosY = woodBlock->pos.y - woodBlock->move.y;

	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			MapChipData mapChipData = GetMapChipData(x, y);
			if (mapChipData.mapChip == 0)continue;

			BlockData* block = mapChipData.data;
			if (CheckSquareSquare(woodBlock->pos.x, prevPosY, woodBlock->width, woodBlock->height,
				block->pos.x, block->pos.y, block->width, block->height))
			{
				//右からあたる
				if (woodBlock->move.x > 0.0f)
				{
					woodBlock->pos.x = block->pos.x - woodBlock->width;
					woodBlock->state = WOOD_BLOCK_STATE_IDLE;
				}

				//左からあたる
				else if (woodBlock->move.x < 0.0f)
				{
					woodBlock->pos.x = block->pos.x + block->width;
					woodBlock->state = WOOD_BLOCK_STATE_IDLE;
				}

				woodBlock->move.x = 0.0f;
			}
		}
	}

	for (int y = 0; y < MAP_CHIP_Y_NUM; y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM; x++)
		{
			MapChipData mapChipData = GetMapChipData(x, y);
			if (mapChipData.mapChip == 0)continue;

			BlockData* block = mapChipData.data;
			if (CheckSquareSquare(woodBlock->pos.x, woodBlock->pos.y, woodBlock->width, woodBlock->height,
				block->pos.x, block->pos.y, block->width, block->height))
			{
				//上からあたる
				if (woodBlock->move.y > 0.0f)
				{
					woodBlock->pos.y = block->pos.y - woodBlock->height;
					woodBlock->state = WOOD_BLOCK_STATE_IDLE;
				}

				//下からあたる
				else if (woodBlock->move.y < 0.0f)
				{
					woodBlock->pos.y = block->pos.y + block->height;
					woodBlock->state = WOOD_BLOCK_STATE_IDLE;
				}

				woodBlock->move.y = 0;
			}
		}
	}
}

void PlayerCollisionHitWoodBlock(Body* body,BodyCollision* bodycollision, WoodBlock* woodBlock)
{
	if (!woodBlock->active)return;

	float prevPosY = body->pos.y- body->move.y;

	if (CheckSquareSquare(body->pos.x + bodycollision->pos.x, prevPosY + bodycollision->pos.y, bodycollision->width, bodycollision->height,
       woodBlock->pos.x, woodBlock->pos.y, woodBlock->width, woodBlock->height))
			{
		//右からあたる
		if (body->move.x > 0.0f)
		{
			body->pos.x = woodBlock->pos.x - bodycollision->width - bodycollision->pos.x;
		}

		//左からあたる
		else if (body->move.x < 0.0f)
		{
			body->pos.x = woodBlock->pos.x + woodBlock->width - bodycollision->pos.x;
		}

		body->move.x = 0.0f;
	}

	if (CheckSquareSquare(body->pos.x + bodycollision->pos.x, body->pos.y + bodycollision->pos.y, bodycollision->width, bodycollision->height,
		woodBlock->pos.x, woodBlock->pos.y, woodBlock->width, woodBlock->height))
	{
		//上からあたる
		if (body->move.y > 0.0f)
		{
			body->pos.y = woodBlock->pos.y - bodycollision->height - bodycollision->pos.y;
			body->feetState = PLAYER_FEET_STATE_BLOCK;
		}

		//下からあたる
		else if (body->move.y < 0.0f)
		{
			body->pos.y = woodBlock->pos.y + woodBlock->height - bodycollision->pos.y;
		}

		body->move.y = 0;
	}
}                                                                                   