#pragma once 
#include "DxLib.h"

#define WOOD_BLOCK_WIDTH (45.0f)
#define WOOD_BLOCK_HEIGHT (45.0f)
#define WOOD_BLOCK_RADIUS (22.5f)

#define WOOD_BLOCK_MOVE_SPEED (10.0f)
#define WOOD_BLOCK_GRAVITY (0.4f)

#define WOOD_BLOCK_MAP_MAX (1.0f)

enum WoodblockState
{
	WOOD_BLOCK_STATE_IDLE,
	WOOD_BLOCK_STATE_MOVE,
	WOOD_BLOCK_STATE_MAX,
};

struct  WoodBlock
{
	VECTOR pos;
	VECTOR move;
	float width;
	float height;
	bool active;
	int hundle;
	WoodblockState state;
};

void InitWoodBlock();
void LoadWoodBlock();
void StepWoodBlock();
void UpdateWoodBlock();
void DrawWoodBlock();
void FinWoodBlock();

WoodBlock* GetWoodBlock();