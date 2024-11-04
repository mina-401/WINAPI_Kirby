#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AItemRoomBeforeBoss :public AActor
{
public:
	// constrcuter destructer
	AItemRoomBeforeBoss();
	~AItemRoomBeforeBoss();

	// delete Function
	AItemRoomBeforeBoss(const AItemRoomBeforeBoss& _Other) = delete;
	AItemRoomBeforeBoss(AItemRoomBeforeBoss&& _Other) noexcept = delete;
	AItemRoomBeforeBoss& operator=(const AItemRoomBeforeBoss& _Other) = delete;
	AItemRoomBeforeBoss& operator=(AItemRoomBeforeBoss&& _Other) noexcept = delete;

protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

