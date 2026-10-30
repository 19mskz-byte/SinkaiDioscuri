#pragma once
#include "MapParameter.h"
#include "../Collision/Collision.h"

void InitMap();
void LoadMap();
void StartMap();
void DrawMap();
void FinMap();

void MoveWithCollision(Body* body);