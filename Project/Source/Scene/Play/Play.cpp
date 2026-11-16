#include "DxLib.h"
#include "Play.h"
#include "../../Map/MapManager.h"
#include "../../Camera/Camera.h"
#include "../../Player/GimmickPlayer.h"
#include "../../Player/PowerfulPlayer.h"
#include "../../Gimmick/WoodBlock/WoodBlock.h"

void InitPlayScene()
{
	InitMap();

	InitCamera();

	InitGimmickPlayer();

	InitPowerfulPlayer();

	InitWoodBlock();
}

void StartPlayScene()
{
	StartMap();

	StartGimmickPlayer();

	StartPowerfulPlayer();
}

void LoadPlayScene()
{
	LoadMap();

	LoadGimmickPlayer();

	LoadPowerfulPlayer();

	LoadWoodBlock();
}
void DrawPlayScene()
{
	DrawMap();

	DrawCamera();

	DrawGimmickPlayer();

	DrawPowerfulPlayer();

	DrawWoodBlock();
}

void UpdatePlayScene()
{
	UpdateGimmickPlayer();

	UpdatePowerfulPlayer();

	UpdateWoodBlock();
}

void FinPlayScene()
{
	FinMap();

	FinGimmickPlayer();

	FinPowerfulPlayer();
	
	FinWoodBlock();
}

void StepPlayScene()
{
	StepCamera();

	StepGimmickPlayer();

	StepPowerfulPlayer();

	StepWoodBlock();
}