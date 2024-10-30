#pragma once
#include <EnginePlatform/EngineWinImage.h>
#include <vector>

// 설명 :
class UEngineSprite : public UObject
{
public:
	class SpriteData
	{
	public:
		// 이 이미지의
		UEngineWinImage* Image;
		// 여기서부터 xx 크기까지
		FTransform Transform;
		// 잘라서 쓰겠다.
	};

	// constrcuter destructer
	UEngineSprite();
	~UEngineSprite();

	// delete Function
	UEngineSprite(const UEngineSprite& _Other) = delete;
	UEngineSprite(UEngineSprite&& _Other) noexcept = delete;
	UEngineSprite& operator=(const UEngineSprite& _Other) = delete;
	UEngineSprite& operator=(UEngineSprite&& _Other) noexcept = delete;

	void PushData(UEngineWinImage* Image, const FTransform& _Trans);

protected:

	std::vector<SpriteData> Data;

	// UEngineWinImage* Image;
};


