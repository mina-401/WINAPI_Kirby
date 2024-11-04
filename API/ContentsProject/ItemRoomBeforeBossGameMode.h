#pragma once
#include <EngineCore/GameMode.h>
// Ό³Έν :
class AItemRoomBeforeBossGameMode : public AGameMode
{
public:
	// constrcuter destructer
	AItemRoomBeforeBossGameMode();
	~AItemRoomBeforeBossGameMode();

	// delete Function
	AItemRoomBeforeBossGameMode(const AItemRoomBeforeBossGameMode& _Other) = delete;
	AItemRoomBeforeBossGameMode(AItemRoomBeforeBossGameMode&& _Other) noexcept = delete;
	AItemRoomBeforeBossGameMode& operator=(const AItemRoomBeforeBossGameMode& _Other) = delete;
	AItemRoomBeforeBossGameMode& operator=(AItemRoomBeforeBossGameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:

};

