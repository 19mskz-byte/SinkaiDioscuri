#include <DxLib.h>
#include "Input.h"

//ç°âÒÇÃì¸óÕ
int g_InputState = 0;
//ëOâÒÇÃì¸óÕ
int g_PrevInputState = 0;

void InitInput()
{
	g_InputState = 0;
	g_PrevInputState = 0;
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
	g_PrevInputState = g_InputState;
	g_InputState = 0;

	if (CheckHitKey(KEY_INPUT_W))
	{
		g_InputState |= KEY_W;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		g_InputState |= KEY_A;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		g_InputState |= KEY_S;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		g_InputState |= KEY_D;
	}
	if (CheckHitKey(KEY_INPUT_I))
	{
		g_InputState |= KEY_I;
	}
	if (CheckHitKey(KEY_INPUT_J))
	{
		g_InputState |= KEY_J;
	}
	if (CheckHitKey(KEY_INPUT_K))
	{
		g_InputState |= KEY_K;
	}
	if (CheckHitKey(KEY_INPUT_L))
	{
		g_InputState |= KEY_L;
	}
	if (CheckHitKey(KEY_INPUT_F))
	{
		g_InputState |= KEY_F;
	}
	if (CheckHitKey(KEY_INPUT_H))
	{
		g_InputState |= KEY_H;
	}
	if (CheckHitKey(KEY_INPUT_U))
	{
		g_InputState |= KEY_U;
	}
}

void DrawInput()
{

}

void FinInput()
{

}

bool IsInputKey(InputKey key)
{
	return g_InputState & key;
}

bool IsTriggerKey(InputKey key)
{
	return (g_InputState & key) && !(g_PrevInputState & key);
}