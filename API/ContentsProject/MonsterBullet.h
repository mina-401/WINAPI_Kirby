
#pragma once
#include <EngineCore/Actor.h>

class AMonsterBullet : public AActor
{
public:
	// constrcuter destructer
	AMonsterBullet();
	~AMonsterBullet();

	//void SetColImage(std::string_view _ColImageName);


	// delete Function
	AMonsterBullet(const AMonsterBullet& _Other) = delete;
	AMonsterBullet(AMonsterBullet&& _Other) noexcept = delete;
	AMonsterBullet& operator=(const AMonsterBullet& _Other) = delete;
	AMonsterBullet& operator=(AMonsterBullet&& _Other) noexcept = delete;

	void SetMainPawn(class AMonster* _MainPawn)
	{
		MainPawn = _MainPawn;
	}

	AMonster* GetMainPawn()
	{
		return MainPawn;
	}

	void InhalingGravity(float _DeltaTime, FVector2D _Vector)
	{

		FVector2D NextPos = _Vector * _DeltaTime * 150.0f;
		AddActorLocation(NextPos);
	}
	bool IsActive = true;
	//void CollisionEnter(AActor* _ColActor);
protected:
	void Tick(float _DeltaTime) override;
	void BeginPlay() override;


private:
	//void DirCheck();
	//void BulletStart();

	//bool BulletNextPosCheck(float _DeltaTime, FVector2D _Vector);

	//class UEngineWinImage* ColImage = nullptr;
	class USpriteRenderer* SpriteRenderer = nullptr;
	class USpriteRenderer* BackSpriteRenderer = nullptr;
	
	class AMonster* MainPawn = nullptr;

	float Speed = 500.0f;

	std::string DirString = "_Right";

	float AlphaTime = 1.0f;
	float AlphaValue = 1.0f;

	FVector2D Vector = FVector2D::ZERO;

};
