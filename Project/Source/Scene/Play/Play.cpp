#include "DxLib.h"
#include "Play.h"
#include "../../Map/MapManager.h"
#include "../../Camera/Camera.h"
#include "../../Player/GimmickPlayer.h"
#include "../../Player/PowerfulPlayer.h"

void InitPlayScene()
{
	InitMap();

	InitCamera();

	InitGimmickPlayer();

	InitPowerfulPlayer();
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
}
void DrawPlayScene()
{
	DrawMap();

	DrawCamera();

	DrawGimmickPlayer();

	DrawPowerfulPlayer();
}

void UpdatePlayScene()
{
	UpdateGimmickPlayer();

	UpdatePowerfulPlayer();
}

void FinPlayScene()
{
	FinMap();

	FinGimmickPlayer();

	FinPowerfulPlayer();
}

void StepPlayScene()
{
	StepCamera();

	StepGimmickPlayer();

	StepPowerfulPlayer();
}