#pragma once

// Ό³Έν :
class ACamera : public AActor
{
public:
	// constrcuter destructer
	ACamera();
	~ACamera();

	// delete Function
	ACamera(const ACamera& _Other) = delete;
	ACamera(ACamera&& _Other) noexcept = delete;
	ACamera& operator=(const ACamera& _Other) = delete;
	ACamera& operator=(ACamera&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void ClickFunction(int _KeyIndex);
protected:

private:

};

