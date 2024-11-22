#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ABullet : public AActor
{
public:
	// constrcuter destructer
	ABullet();
	~ABullet();

	void SetColImage(std::string_view _ColImageName);


	// delete Function
	ABullet(const ABullet& _Other) = delete;
	ABullet(ABullet&& _Other) noexcept = delete;
	ABullet& operator=(const ABullet& _Other) = delete;
	ABullet& operator=(ABullet&& _Other) noexcept = delete;

	void SetMainPawn(class APlayer* _MainPawn)
	{
		MainPawn = _MainPawn;
	}

	APlayer* GetMainPawn()
	{
		return MainPawn;
	}
	void CollisionEnter(AActor* _ColActor);
protected:
	void Tick(float _DeltaTime) override;
	void BeginPlay() override;


private:
	void DirCheck();
	void BulletStart();

	bool BulletNextPosCheck(float _DeltaTime, FVector2D _Vector);

	class UEngineWinImage* ColImage = nullptr;
	class USpriteRenderer* SpriteRenderer = nullptr;

	class APlayer* MainPawn = nullptr;

	float Speed = 500.0f;

	std::string DirString = "_Right";

	FVector2D Vector = FVector2D::ZERO;
};

