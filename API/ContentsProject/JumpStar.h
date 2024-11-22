#pragma once

#include <EngineCore/Actor.h>

class AJumpStar : public AActor
{
public:
	// constrcuter destructer
	AJumpStar();
	~AJumpStar();

	void SetColImage(std::string_view _ColImageName);

	// delete Function
	AJumpStar(const AJumpStar& _Other) = delete;
	AJumpStar(AJumpStar&& _Other) noexcept = delete;
	AJumpStar& operator=(const AJumpStar& _Other) = delete;
	AJumpStar& operator=(AJumpStar&& _Other) noexcept = delete;
	void JumpGravity(float _DeltaTime)
	{
		if (false == IsGround)
		{
			GravityForce += FVector2D::DOWN * _DeltaTime * 0.4f;
			AddActorLocation(GravityForce);
		}
		else {
			GravityForce = FVector2D::ZERO;
		}

	}
protected:
	void Tick(float _DeltaTime) override;
	void BeginPlay() override;
	void SetForegroundColImage();
	bool StarNextPosCheck(float _DeltaTime, FVector2D _Vector);
private:
	FVector2D Vector = FVector2D::RIGHT;
	FVector2D JumpPower = { 0.0f,-300.0f };
	FVector2D GravityForce = FVector2D::ZERO;
	float Speed = 300.0f;
	class UEngineWinImage* ColImage = nullptr;
	class USpriteRenderer* SpriteRenderer = nullptr;
	bool IsGround = false;
	
};

