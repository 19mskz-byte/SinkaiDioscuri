#include <DxLib.h>
#include "Input.h"

//ç°âÒÇÃì¸óÕ
int g_PowerfulInputState = 0;
//ëOâÒÇÃì¸óÕ
int g_PrevPowerfulInputState = 0;

//ç°âÒÇÃì¸óÕ
int g_GimmickInputState = 0;
//ëOâÒÇÃì¸óÕ
int g_PrevGimmickInputState = 0;


void InitInput()
{
	g_PowerfulInputState = 0;
	g_PrevPowerfulInputState = 0;
	g_GimmickInputState = 0;
	g_PrevGimmickInputState = 0;
}

void StartInput()
{
				
}

void LoadInput()
{

}

void StepInput()
{

}

void UpdateInput()
{
	g_PrevPowerfulInputState = g_PowerfulInputState;
	g_PowerfulInputState = 0;
	g_PrevGimmickInputState = g_GimmickInputState;
	g_GimmickInputState = 0;

	if (CheckHitKey(KEY_INPUT_W))
	{
		g_PowerfulInputState |= KEY_W;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		g_PowerfulInputState |= KEY_A;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		g_PowerfulInputState |= KEY_S;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		g_PowerfulInputState |= KEY_D;
	}
	if (CheckHitKey(KEY_INPUT_I))
	{
		g_GimmickInputState |= KEY_I;
	}
	if (CheckHitKey(KEY_INPUT_J))
	{
		g_GimmickInputState |= KEY_J;
	}
	if (CheckHitKey(KEY_INPUT_K))
	{
		g_GimmickInputState |= KEY_K;
	}
	if (CheckHitKey(KEY_INPUT_L))
	{
		g_GimmickInputState |= KEY_L;
	}
	if (CheckHitKey(KEY_INPUT_F))
	{
		g_PowerfulInputState |= KEY_F;
	}
	if (CheckHitKey(KEY_INPUT_H))
	{
		g_GimmickInputState |= KEY_H;
	}
	if (CheckHitKey(KEY_INPUT_U))
	{
		g_GimmickInputState |= KEY_U;
	}
}

void DrawInput()
{

}

void FinInput()
{

}

bool IsPowerfulInputKey(InputKey key)
{
	return g_PowerfulInputState & key;
}

bool IsTriggerPowerfulInputKey(InputKey key)
{
	return (g_PowerfulInputState & key) && !(g_PrevPowerfulInputState & key);
}

bool IsReleasePowerfulInputKey(InputKey key)
{
	return !(g_PowerfulInputState & key) && (g_PrevPowerfulInputState & key);
}

bool IsGimmickInputKey(InputKey key)
{
	return g_GimmickInputState & key;
}

bool IsTriggerGimmickInputKey(InputKey key)
{
	return (g_GimmickInputState & key) && !(g_PrevGimmickInputState & key);
}

bool IsReleaseGimmickInputKey(InputKey key)
{
	return !(g_GimmickInputState & key) && (g_PrevGimmickInputState & key);
}
