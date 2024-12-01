#pragma once

#include <EngineCore/Actor.h>

// ���� :
class AEndingMap :public AActor
{
public:
	// constrcuter destructer
	AEndingMap();
	~AEndingMap();

	// delete Function
	AEndingMap(const AEndingMap& _Other) = delete;
	AEndingMap(AEndingMap&& _Other) noexcept = delete;
	AEndingMap& operator=(const AEndingMap& _Other) = delete;
	AEndingMap& operator=(AEndingMap&& _Other) noexcept = delete;
	void BeginPlay() override;
	void Tick(float _deltaTime) override;


protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
	class USpriteRenderer* ColSpriteRenderer = nullptr;
	FVector2D MapScale;

};

