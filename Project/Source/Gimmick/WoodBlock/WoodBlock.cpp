#include "WoodBlock.h"
#include "../../Collision/Collision.h"
#include "../../Camera/Camera.h"

WoodBlock g_WoodBlock = { 0 };

void InitWoodBlock()
{
	for (int i = 0; i < WOOD_BLOCK_MAP_MAX; i++)
	{
		g_WoodBlock.pos.x =500.0f;
		g_WoodBlock.pos.y = 600.0f;
		g_WoodBlock.move.x = 0.0f;
		g_WoodBlock.move.y = 0.0f;
		g_WoodBlock.active = true;
		g_WoodBlock.hundle = 0;
		g_WoodBlock.width = WOOD_BLOCK_WIDTH;
		g_WoodBlock.height = WOOD_BLOCK_HEIGHT;
	}
}

void LoadWoodBlock()
{
	if (!g_WoodBlock.active) return;
	for (int i = 0; i < WOOD_BLOCK_MAP_MAX; i++)
	{
		if (!g_WoodBlock.active) return;
		g_WoodBlock.hundle = LoadGraph("Data/Gimmick/WoodBlock.png");
	}
}

void StepWoodBlock()
{
	if (!g_WoodBlock.active) return;
	for (int i = 0; i < WOOD_BLOCK_MAP_MAX; i++)
	{
		if (!g_WoodBlock.active) return;

		g_WoodBlock.move.x = 0;

		g_WoodBlock.move.y += WOOD_BLOCK_GRAVITY;
	}
}

void UpdateWoodBlock()
{
	if (!g_WoodBlock.active) return;
	for (int i = 0; i < WOOD_BLOCK_MAP_MAX; i++)
	{
		if (!g_WoodBlock.active) return;
		g_WoodBlock.pos.x += g_WoodBlock.move.x;
		g_WoodBlock.pos.y += g_WoodBlock.move.y;
		WoodBlockHitMapBlock(&g_WoodBlock);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "–Ø” ‚ÌÀ•W[%f, %f]", g_WoodBlock.pos.x, g_WoodBlock.pos.y);
	}
}

void DrawWoodBlock()
{
	if (!g_WoodBlock.active) return;
	CameraData camera = GetCamera();

	for (int i = 0; i < WOOD_BLOCK_MAP_MAX; i++)
	{
		DrawGraph((int)(g_WoodBlock.pos.x), (int)(g_WoodBlock.pos.y - camera.pos.y), g_WoodBlock.hundle, TRUE);
	}
}

void FinWoodBlock()
{
	if (!g_WoodBlock.active) return;
	for (int i = 0; i < WOOD_BLOCK_MAP_MAX; i++)
	{
		if (!g_WoodBlock.active) return;
		DeleteGraph(g_WoodBlock.hundle);
	}
}

WoodBlock* GetWoodBlock()
{
	return &g_WoodBlock;
}