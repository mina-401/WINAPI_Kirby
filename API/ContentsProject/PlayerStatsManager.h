#pragma once

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
protected:

private:
	PlayerStatsManager();

	int Life;

};

