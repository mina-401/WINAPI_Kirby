#pragma once
#include "ContentsEnum.h"

// Ό³Έν :
class PlayerStatsManager
{
public:
	// constrcuter destructer
	
	~PlayerStatsManager();

	// delete Function
	PlayerStatsManager(const PlayerStatsManager& _Other) = delete;
	PlayerStatsManager(PlayerStatsManager&& _Other) noexcept = delete;
	PlayerStatsManager& operator=(const PlayerStatsManager& _Other) = delete;
	PlayerStatsManager& operator=(PlayerStatsManager&& _Other) noexcept = delete;

	static PlayerStatsManager& GetInst()
	{
		static PlayerStatsManager Inst;
		return Inst;
	}


	int GetLife() const
	{
		return Life;
	}

	void SetLife(int Count)
	{
		Life = Count;
	}

	int GetAddLife(int _Count)
	{
		Life += _Count;
		return Life;
	}
	int GetMinusLife(int _Count)
	{
		Life -= _Count;
		return Life;
	}

	ECopyAbilityState GetCopyAbilityState()
	{
		return PlayerStats;
	}

	void SetCopyAbilityState(ECopyAbilityState _Copy)
	{
		PlayerStats = _Copy;
	}

	float GetHp() const
	{
		return Hp;
	}
	void SetHp(float _hp)
	{
		Hp = _hp;
	}

protected:

private:
	PlayerStatsManager();

	int Life;
	float Hp;
	ECopyAbilityState PlayerStats;
};

