#pragma once
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class SoundManager
{
public:
	// constrcuter destructer
	~SoundManager();

	// delete Function
	SoundManager(const SoundManager& _Other) = delete;
	SoundManager(SoundManager&& _Other) noexcept = delete;
	SoundManager& operator=(const SoundManager& _Other) = delete;
	SoundManager& operator=(SoundManager&& _Other) noexcept = delete;
	static SoundManager& GetInst()
	{
		static SoundManager Inst;
		return Inst;
	}
	USoundPlayer& GetSoundPlayer()
	{
		return BGMPlayer;
	}

	void SetSoundPlayer(USoundPlayer& _Player)
	{
		BGMPlayer = _Player;
	}
protected:

private:
	SoundManager();

	USoundPlayer BGMPlayer;
};

