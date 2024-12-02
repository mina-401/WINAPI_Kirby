#pragma once

#include <EngineCore/Actor.h>
#include "ContentsEnum.h"  
#include <EnginePlatform/EngineSound.h>

class AHPItem : public AActor
{
public:
	// constrcuter destructer
	AHPItem();
	~AHPItem();

	void CollisionEnter(AActor* _ColActor);

	// delete Function
	AHPItem(const AHPItem& _Other) = delete;
	AHPItem(AHPItem&& _Other) noexcept = delete;
	AHPItem& operator=(const AHPItem& _Other) = delete;
	AHPItem& operator=(AHPItem&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	void SetMainPawn(class APlayer* _MainPawn)
	{
		MainPawn = _MainPawn;
	}

protected:
	class USpriteRenderer* SpriteRenderer = nullptr;
	class U2DCollision* CollisionComponent = nullptr;
private:

	USoundPlayer BGMPlayer;
	class APlayer* MainPawn = nullptr;

};
