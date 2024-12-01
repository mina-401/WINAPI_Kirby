#pragma once
#include <EngineCore/Actor.h>

// ���� :
class AFade : public AActor
{
public:
	static AFade* MainFade;

public:
	// constrcuter destructer
	AFade();
	~AFade();

	// delete Function
	AFade(const AFade& _Other) = delete;
	AFade(AFade&& _Other) noexcept = delete;
	AFade& operator=(const AFade& _Other) = delete;
	AFade& operator=(AFade&& _Other) noexcept = delete;

	// 0 => 1
	void FadeIn(float _val);

	// 1 => 0
	void FadeOut(float _val);
	float FadeValue = 0.0f;

protected:

private:
	void LevelChangeStart() override;
	float FadeDir = 1.0f;
	USpriteRenderer* BackSpriteRenderer;
	void FadeChange();

};

