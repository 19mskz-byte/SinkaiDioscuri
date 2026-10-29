#pragma once
#include "DxLib.h"

#define BLOCK_MAX (1024)
#define MAP_CHIP_X_NUM (36)
#define MAP_CHIP_Y_NUM (30)
#define MAP_CHIP_WIDTH (45.0f)
#define MAP_CHIP_HEIGHT (45.0f)

enum MapChipType
{
	MAP_CHIP_NONE,
	NORMAL_BLOCK,
	BLOCK_TYPE_MAX,
};

struct BlockData
{
	bool active;
	int handle;
	MapChipType type;
	VECTOR pos;
};

struct MapChipData
{
	int mapChip;
	BlockData* data;
};
