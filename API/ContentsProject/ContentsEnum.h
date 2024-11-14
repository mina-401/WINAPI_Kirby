#pragma once


enum class ERenderOrder
{
	BACKGROUND = -1000,
	COLMAP = -1001,
	FOREGROUND = -999,
	PLAYER = 0,
	MONSTER = 0,
	UI = 10000,
};
enum class ECollisionGroup
{
	PlayerBody,
	MonsterBody,
	MonsterAttack,
	SpawnPoint,
	Potal,
};
