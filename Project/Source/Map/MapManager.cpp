#include "MapManager.h"
#include "MapParameter.h"
#include "MapChip.h"
#include "Block.h"
#include "../Player/GimmickPlayer.h"
#include "../Player/PowerfulPlayer.h"

// キャラクターの周囲何マスまでチェックするか
#define CHECK_ROUND_NUM (2)

void InitMap()
{
}

void LoadMap()
{
	LoadMapChipData();
	LoadBlock();
}

void StartMap()
{
	CreateMap();
}

void DrawMap()
{
	// ブロック描画
	DrawBlock();
}

void FinMap()
{
}

//void CheckMapGimmickPlayerCollision()
//{
//	GimmickPlayerData* player = GetGimmickPlayer();
//
//	// プレイヤーの足元の座標をマップチップのインデックスに変換
//	int playerX = (int)(player->pos.x / MAP_CHIP_WIDTH);
//	int playerY = (int)((player->pos.y + GIMMICK_PLAYER_HEIGHT) / MAP_CHIP_HEIGHT);
//	// プレイヤーの左上にあるマップチップインデックス
//	int left = playerX - CHECK_ROUND_NUM;
//	int top = playerY - CHECK_ROUND_NUM;
//	// プレイヤーの右下にあるマップチップインデックス
//	int right = playerX + CHECK_ROUND_NUM;
//	int bottom = playerY + CHECK_ROUND_NUM;
//
//	// 左上から3マスずつチェックしていく
//	for (int y = top; y <= bottom; y++)
//	{
//		// マップチップからはみ出したら処理しなくていい
//		if (y < 0 || y >= MAP_CHIP_Y_NUM) continue;
//
//		for (int x = left; x <= right; x++)
//		{
//			// マップチップからはみ出したら処理しなくていい
//			if (x < 0 || x >= MAP_CHIP_X_NUM) continue;
//
//			// マップチップ番号を取得
//			MapChipData mapChipData = GetMapChipData(x, y);
//			switch (mapChipData.mapChip)
//			{
//			case NORMAL_BLOCK:
//				GimmickPlayerHitNormalBlock(mapChipData);
//				break;
//			}
//		}
//	}
//}
//
//void CheckMapPowerfulPlayerCollision()
//{
//	PowerfulPlayerData* player = GetPowerfulPlayer();
//
//	// プレイヤーの足元の座標をマップチップのインデックスに変換
//	int playerX = (int)(player->pos.x / MAP_CHIP_WIDTH);
//	int playerY = (int)((player->pos.y + POWERFUL_PLAYER_HEIGHT) / MAP_CHIP_HEIGHT);
//	// プレイヤーの左上にあるマップチップインデックス
//	int left = playerX - CHECK_ROUND_NUM;
//	int top = playerY - CHECK_ROUND_NUM;
//	// プレイヤーの右下にあるマップチップインデックス
//	int right = playerX + CHECK_ROUND_NUM;
//	int bottom = playerY + CHECK_ROUND_NUM;
//
//	// 左上から3マスずつチェックしていく
//	for (int y = top; y <= bottom; y++)
//	{
//		// マップチップからはみ出したら処理しなくていい
//		if (y < 0 || y >= MAP_CHIP_Y_NUM) continue;
//
//		for (int x = left; x <= right; x++)
//		{
//			// マップチップからはみ出したら処理しなくていい
//			if (x < 0 || x >= MAP_CHIP_X_NUM) continue;
//
//			// マップチップ番号を取得
//			MapChipData mapChipData = GetMapChipData(x, y);
//			switch (mapChipData.mapChip)
//			{
//			case NORMAL_BLOCK:
//				PowerfulPlayerHitNormalBlock(mapChipData);
//				break;
//			}
//		}
//	}
//}

void MoveWithCollision(Body* body,BodyCollision* bodycollision)
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
			if (CheckSquareSquare(body->pos.x+bodycollision->pos.x, prevPosY+bodycollision->pos.y, bodycollision->width, bodycollision->height,
				block->pos.x, block->pos.y, block->width, block->height))
			{
				//右からあたる
				if (body->move.x > 0.0f)
				{
					body->pos.x = block->pos.x - bodycollision->width-bodycollision->pos.x;
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