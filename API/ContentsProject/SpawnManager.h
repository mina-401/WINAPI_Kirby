#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ASpawnManager : public AActor
{
public:
	// constrcuter destructer
	ASpawnManager();
	~ASpawnManager();

	// delete Function
	ASpawnManager(const ASpawnManager& _Other) = delete;
	ASpawnManager(ASpawnManager&& _Other) noexcept = delete;
	ASpawnManager& operator=(const ASpawnManager& _Other) = delete;
	ASpawnManager& operator=(ASpawnManager&& _Other) noexcept = delete;

protected:

private:

};

