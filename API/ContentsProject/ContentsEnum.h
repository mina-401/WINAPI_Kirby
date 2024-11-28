#pragma once


enum class ERenderOrder
{
	BACKGROUND = -1000,
	FOREGROUND = -999,
	COLMAP = -1001,
	PLAYER = 0,
	MONSTER = 0,
	UI = 10000,
};
enum class ECollisionGroup
{
	PlayerBody,
	PlayerInvincible,
	PlayerInhaleRange,
	MonsterBody,
	MonsterAttack,
	SpawnPoint,
	Potal,
	Block,
};
enum class EPlayerState
{
	Idle,
	Crouch,
	Move,
	Dash,
	Break,
	Jump,
	Fly,
	FlyDown,
	Slide,
	Attack,
	Inhale,
	Exhale,
	KnockBack,
	Die,
	Change,
};

enum class EPlayerEatState
{
	Normal,
	Eating,

};
enum class EMonsterState
{
	Idle,
	Move,
	Chase,
	Attack,
	Inhaled,
	Hurt,
	KnockBack,
	Die,
};


enum class ECopyAbilityState
{
	Normal,
	Fire,
	Spark,
	Beam,
};