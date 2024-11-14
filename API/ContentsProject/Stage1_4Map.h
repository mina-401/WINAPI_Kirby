#pragma once

// Ό³Έν :
class AStage1_4Map : public AActor
{
public:
	// constrcuter destructer
	AStage1_4Map();
	~AStage1_4Map();

	// delete Function
	AStage1_4Map(const AStage1_4Map& _Other) = delete;
	AStage1_4Map(AStage1_4Map&& _Other) noexcept = delete;
	AStage1_4Map& operator=(const AStage1_4Map& _Other) = delete;
	AStage1_4Map& operator=(AStage1_4Map&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _deltaTime) override;

	void CollisionEnter(AActor* _ColActor);
	void CollisionStay(AActor* _ColActor);
	void CollisionEnd(AActor* _ColActor);
protected:

private:

	FVector2D PngSize;
	FVector2D WinSize;
	FVector2D MapScale;

	class AStageBackground* BackGroundMap = nullptr;
	class USpriteRenderer* SpriteRenderer = nullptr;
	class USpriteRenderer* ColSpriteRenderer = nullptr;

	class U2DCollision* PotalColComponent = nullptr;

	bool IsPlayerStayPotal = false;
};



