#pragma once
#include <EngineCore/Actor.h>

// ���� :
class AStage1_1Map :public AActor
{
public:
	// constrcuter destructer
	AStage1_1Map();
	~AStage1_1Map();


	

	// delete Function
	AStage1_1Map(const AStage1_1Map& _Other) = delete;
	AStage1_1Map(AStage1_1Map&& _Other) noexcept = delete;
	AStage1_1Map& operator=(const AStage1_1Map& _Other) = delete;
	AStage1_1Map& operator=(AStage1_1Map&& _Other) noexcept = delete;
	void BeginPlay() override;
	void Tick(float _deltaTime) override;
	void CollisionEnter(AActor* _ColActor);
	void CollisionStay(AActor* _ColActor);
	void CollisionEnd(AActor* _ColActor);
protected:

private:
	
private:
	FVector2D PngSize;
	FVector2D WinSize;
	FVector2D MapScale;
	class USpriteRenderer* SpriteRenderer = nullptr;
	class USpriteRenderer* ColSpriteRenderer = nullptr;
	class USpriteRenderer* StarSpriteRenderer = nullptr;

	class U2DCollision* PotalColComponent = nullptr;

	bool IsPlayerStayPotal = false;
};

