#include "DxLib.h"
#include "Play.h"
#include "../../Map/MapManager.h"
#include "../../Camera/Camera.h"

void InitPlayScene()
{
	InitMap();

	InitCamera();

	/*InitPlayer();*/
}

void StartPlayScene()
{
	StartMap();

	/*StartPlayer();*/
}

void LoadPlayScene()
{
	LoadMap();

	/*LoadPlayer();*/
}
void DrawPlayScene()
{
	DrawMap();

	DrawCamera();


	/*DrawPlayer();*/
}

void UpdatePlayScene()
{

	/*UpdatePlayer();*/
}

void FinPlayScene()
{
	FinMap();

	/*FinPlayer();*/
}

void StepPlayScene()
{
	StepCamera();

	/*StepPlayer();*/
}