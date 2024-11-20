#pragma once

#include <EngineCore/Actor.h>
// Ό³Έν :
class AWidget : public AActor
{
public:
	// constrcuter destructer
	AWidget();
	~AWidget();

	// delete Function
	AWidget(const AWidget& _Other) = delete;
	AWidget(AWidget&& _Other) noexcept = delete;
	AWidget& operator=(const AWidget& _Other) = delete;
	AWidget& operator=(AWidget&& _Other) noexcept = delete;
	void SetDamagePower(float _Power)
	{
		DamagePower = _Power;
	}

	
protected:
	float TotalDamage = 0.0f;
	float DamagePower = 50.0f;
protected:

private:
	
};

