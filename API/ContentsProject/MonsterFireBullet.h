#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AMonsterFireBullet : public AActor
{
public:
	// constrcuter destructer
	AMonsterFireBullet();
	~AMonsterFireBullet();

	// delete Function
	AMonsterFireBullet(const AMonsterFireBullet& _Other) = delete;
	AMonsterFireBullet(AMonsterFireBullet&& _Other) noexcept = delete;
	AMonsterFireBullet& operator=(const AMonsterFireBullet& _Other) = delete;
	AMonsterFireBullet& operator=(AMonsterFireBullet&& _Other) noexcept = delete;
	void SetMainPawn(class AHotHead* _MainPawn)
	{
		MainPawn = _MainPawn;
	}

	AHotHead* GetMainPawn()
	{
		return MainPawn;
	}

	void SetIsBoome(bool _Is)
	{
		IsBoome = _Is;
	}
protected:

	void Tick(float _DeltaTime) override;
	void BeginPlay() override;
private:
	void DirCheck();
	void FireBulletStart();
	void FireboomerangStart();

	bool IsBoome = true;

	class USpriteRenderer* SpriteRenderer = nullptr;

	class AHotHead* MainPawn = nullptr;

	std::string DirString = "_Right";


	FVector2D Vector = FVector2D::ZERO;
	FVector2D PlayerDir = FVector2D::ZERO;
};

