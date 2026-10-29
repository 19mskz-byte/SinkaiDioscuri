#pragma once

enum InputKey
{
	KEY_W = (1 << 0),
	KEY_A = (1 << 1),
	KEY_S = (1 << 2),
	KEY_D = (1 << 3),
	KEY_I = (1 << 4),
	KEY_J = (1 << 5),
	KEY_K = (1 << 6),
	KEY_L = (1 << 7),
	KEY_F = (1 << 8),
	KEY_U = (1 << 9),
	KEY_H = (1 << 10),
};

void InitInput();
void StartInput();
void LoadInput();
void StepInput();
void UpdateInput();
void DrawInput();
void FinInput();

//キー入力判定
bool IsInputKey(InputKey);
//キー押した瞬間判定
bool IsTriggerKey(InputKey);
