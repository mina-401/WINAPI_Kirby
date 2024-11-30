#include "PreCompile.h"
#include "EngineSprite.h"
#include <EngineBase/EngineDebug.h>

UEngineSprite::UEngineSprite()
{
}

UEngineSprite::~UEngineSprite()
{
}


void UEngineSprite::PushData(UEngineWinImage* _Image, const FTransform& _Trans)
{
	if (true == _Trans.Scale.IsZeroed())
	{
		MSGASSERT("ũ�Ⱑ 0�� �̹����� ����� �����ϴ�");
	}
	

	// ����Ʈ �̴ϼȶ�����
	Data.push_back({ _Image, _Trans });
}


