#pragma once
#include <EngineCore/Actor.h>
// Ό³Έν :
class ABlock : public AActor
{
public:
	// constrcuter destructer
	ABlock();
	~ABlock();

	void Tick(float _DeltaTime) override;
	void BeginPlay() override;

	// delete Function
	ABlock(const ABlock& _Other) = delete;
	ABlock(ABlock&& _Other) noexcept = delete;
	ABlock& operator=(const ABlock& _Other) = delete;
	ABlock& operator=(ABlock&& _Other) noexcept = delete;
	void InhalingGravity(float _DeltaTime, FVector2D _Vector)
	{

		FVector2D NextPos = _Vector * _DeltaTime * Speed;
		AddActorLocation(NextPos);
	}
protected:
	float Speed = 150.0f;
private:
	class USpriteRenderer* SpriteRenderer = nullptr;
};

