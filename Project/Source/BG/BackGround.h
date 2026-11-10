#pragma once
#include "Dxlib.h"

void BackGroundInit();
void BackGroundLoad();
void BackGroundStep();
void BackGroundUpdate();
void BackGroundDraw();
void BackGroundFin();

struct  BG
{
	int hundle;
	VECTOR pos;
};