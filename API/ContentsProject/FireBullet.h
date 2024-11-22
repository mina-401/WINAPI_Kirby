#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AFireBullet : public AActor
{
public:
	// constrcuter destructer
	AFireBullet();
	~AFireBullet();

	// delete Function
	AFireBullet(const AFireBullet& _Other) = delete;
	AFireBullet(AFireBullet&& _Other) noexcept = delete;
	AFireBullet& operator=(const AFireBullet& _Other) = delete;
	AFireBullet& operator=(AFireBullet&& _Other) noexcept = delete;
	void SetMainPawn(class APlayer* _MainPawn)
	{
		MainPawn = _MainPawn;
	}

	APlayer* GetMainPawn()
	{
		return MainPawn;
	}
protected:

	void Tick(float _DeltaTime) override;
	void BeginPlay() override;
private:
	void DirCheck();

	void FireBulletStart();


	class USpriteRenderer* SpriteRenderer = nullptr;

	class APlayer* MainPawn = nullptr;

	std::string DirString = "_Right";

	FVector2D Vector = FVector2D::ZERO;
};

