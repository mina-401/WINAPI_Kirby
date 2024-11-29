// Ό³Έν :
#pragma once
#include <EngineCore/Actor.h>
class AStarBlock : public AActor
{
public:
	// constrcuter destructer
	AStarBlock();
	~AStarBlock();



	// delete Function
	AStarBlock(const AStarBlock& _Other) = delete;
	AStarBlock(AStarBlock&& _Other) noexcept = delete;
	AStarBlock& operator=(const AStarBlock& _Other) = delete;
	AStarBlock& operator=(AStarBlock&& _Other) noexcept = delete;


	void InhalingGravity(float _DeltaTime, FVector2D _Vector)
	{

		FVector2D NextPos = _Vector * _DeltaTime * 150.0f;
		AddActorLocation(NextPos);
	}
	void SetIshale(bool _Value)
	{
		Ishaling = _Value;
	}

protected:
	void Tick(float _DeltaTime) override;
	void BeginPlay() override;
private:
	bool Ishaling = false;
};