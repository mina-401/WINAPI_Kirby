#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AItemRoomBeforeBossMap :public AActor
{
public:
	// constrcuter destructer
	AItemRoomBeforeBossMap();
	~AItemRoomBeforeBossMap();

	// delete Function
	AItemRoomBeforeBossMap(const AItemRoomBeforeBossMap& _Other) = delete;
	AItemRoomBeforeBossMap(AItemRoomBeforeBossMap&& _Other) noexcept = delete;
	AItemRoomBeforeBossMap& operator=(const AItemRoomBeforeBossMap& _Other) = delete;
	AItemRoomBeforeBossMap& operator=(AItemRoomBeforeBossMap&& _Other) noexcept = delete;
	void BeginPlay() override;
	void Tick(float _deltaTime) override;
protected:

private:
	FVector2D PngSize;
	FVector2D WinSize;
	FVector2D MapScale;
	class USpriteRenderer* SpriteRenderer = nullptr;
	class USpriteRenderer* ColSpriteRenderer = nullptr;
};

