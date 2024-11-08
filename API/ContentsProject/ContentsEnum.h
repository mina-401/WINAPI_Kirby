#pragma once


enum class ERenderOrder
{
	BACKGROUND = -1000,
	COLMAP = -998,
	FOREGROUND = -999,
	PLAYER = 0,
	UI = 10000,
};
enum class ECollisionGroup
{
	PlayerBody,
	MonsterBody,
};
