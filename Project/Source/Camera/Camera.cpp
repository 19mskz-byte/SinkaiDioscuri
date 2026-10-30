#include "DxLib.h"
#include "Camera.h"
#include "../Input/Input.h"
#include "../Player/GimmickPlayer.h"
#include "../Map/MapChip.h"

#define DEBUG_CAMERA_SPEED (4.0f)
#define CAMERA_SCROOL_START_X (200.0f)

CameraData g_CameraData = { 0 };

void InitCamera()
{

}

void StepCamera()
{
	g_CameraData.pos.x = 1000;

	g_CameraData.pos.y = 500;
}

void DrawCamera()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ÉJÉÅÉâÇÃç¿ïWÅÅ[%f, %f]", g_CameraData.pos.x, g_CameraData.pos.y);
}

CameraData GetCamera()
{
	return g_CameraData;
}