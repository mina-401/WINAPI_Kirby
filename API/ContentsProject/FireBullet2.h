#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AFireBullet2 : public AActor
{
public:
	// constrcuter destructer
	AFireBullet2();
	~AFireBullet2();

	// delete Function
	AFireBullet2(const AFireBullet2& _Other) = delete;
	AFireBullet2(AFireBullet2&& _Other) noexcept = delete;
	AFireBullet2& operator=(const AFireBullet2& _Other) = delete;
	AFireBullet2& operator=(AFireBullet2&& _Other) noexcept = delete;

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


	class USpriteRenderer* SpriteRenderer1 = nullptr;
	class USpriteRenderer* SpriteRenderer2= nullptr;
	class USpriteRenderer* SpriteRenderer3 = nullptr;

	class APlayer* MainPawn = nullptr;

	std::string DirString = "_Right";

	FVector2D Vector = FVector2D::ZERO;
};

