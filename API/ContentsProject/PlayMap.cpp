#include "PreCompile.h"
#include "PlayMap.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"

APlayMap::APlayMap()
{
	// �Ź� ������ ����� �ٲ��
	// �̰� ��ü�� ��� ������ �ƴմϴ�.
	{
		SetActorScale({ 1, 1 });
		SetActorLocation({ 0,0 });

		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
		SpriteRenderer->SetSprite("Title.png");

		FVector2D Size= UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		SpriteRenderer->SetComponentScale(Size*0.7);
		
		SpriteRenderer->SetComponentLocation(Size.Half());

		FTransform tfrom= SpriteRenderer->Sprite->GetSpriteData().Transform;
		//FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.f);


		int a = 0;
	}
}

APlayMap::~APlayMap()
{
}

