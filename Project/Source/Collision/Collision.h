#pragma once
#include "DxLib.h"
#include "../Gimmick/WoodBlock/WoodBlock.h"

enum PlayerFeetState
{
	PLAYER_FEET_STATE_AIR,
	PLAYER_FEET_STATE_BLOCK,
	PLAYER_FEET_STATE_STEPLADDER,
	PLAYER_FEET_STATE_MAX,
};

struct BodyCollision
{
	bool isAir;
	VECTOR pos;
	VECTOR move;
	float width;
	float height;
};

struct Body
{
	bool isAir;
	VECTOR pos;
	VECTOR move;
	float width;
	float height;
	PlayerFeetState feetState;
};


// 矩形と点の当たり判定
bool CheckSquarePoint(float squarePosX, float squarePosY, float squareWidth, float squareHeight, float pointX, float pointY);

// 矩形と矩形の当たり判定
bool CheckSquareSquare(float squareA_PosX, float squareA_PosY, float squareA_Width, float squareA_Height, float squareB_PosX, float squareB_PosY, float squareB_Width, float squareB_Height);

// 円と点の当たり判定
bool CheckCirclePoint(float circlePosX, float circlePosY, float circleRadius, float pointX, float pointY);

// 円と円の当たり判定
bool CheckCircleCircle(float circleA_PosX, float circleA_PosY, float circleA_Radius, float circleB_PosX, float circleB_PosY, float circleB_Radius);

//プレイヤーとブロックの当たり判定
void MoveWithCollision(Body* body, BodyCollision* bodycollision);

//ブロックと木箱の当たり判定
void WoodBlockHitMapBlock(WoodBlock* woodBlock);

//プレイヤーと木箱の当たり判定
void PlayerCollisionHitWoodBlock(Body* body, BodyCollision* bodycollision, WoodBlock* woodBlock);

//木箱が置けるかどうか
bool LimitWoodBlockPutBlock(Body* body, bool isTurn, BodyCollision* bodycollision, WoodBlock* woodBlock);