#include "PreCompile.h"
#include "KirbyWidget.h"
#include "ContentsEnum.h"
#include "Player.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>

AKirbyWidget::AKirbyWidget()
{
	DebugOn();
	{
		SetName("MainHud");
		
		
		{
			Icon = CreateDefaultSubObject<USpriteRenderer>();
			Icon->SetOrder(ERenderOrder::UI);

			UImageManager::GetInst().CuttingSprite("LifeIcon.png", { 55, 30 });
			Icon->SetSprite("LifeIcon.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

			MapScale = Icon->SetSpriteScale(1.0f);
		}

		{
			Life = CreateDefaultSubObject<USpriteRenderer>();
			Life->SetOrder(ERenderOrder::UI);

			UImageManager::GetInst().CuttingSprite("Font2.png", { 21, 25 });
			Life->SetSprite("Font2.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

			MapScale = Life->SetSpriteScale(1.0f);
		} 
		{
			HpBarCase = CreateDefaultSubObject<USpriteRenderer>();
			HpBarCase->SetOrder(ERenderOrder::UI);

			UImageManager::GetInst().CuttingSprite("KirbyHpBarCase.png", { 215, 30 });
			HpBarCase->SetSprite("KirbyHpBarCase.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
			MapScale = HpBarCase->SetSpriteScale(1.0f);
		}
		{
			HpBar = CreateDefaultSubObject<USpriteRenderer>();
			HpBar->SetOrder(ERenderOrder::UI);

			UImageManager::GetInst().CuttingSprite("KirbyHp.png", { 183, 21 });
			HpBar->SetSprite("KirbyHp.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
			MapScale = HpBar->SetSpriteScale(1.0f);
		}
		{
			NameTag = CreateDefaultSubObject<USpriteRenderer>();
			NameTag->SetOrder(ERenderOrder::UI);

			UImageManager::GetInst().CuttingSprite("nametag_normal.png", { 214, 190 });
			NameTag->SetSprite("nametag_normal.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
			
			MapScale = NameTag->SetSpriteScale(1.0f);
		}
	}
}

AKirbyWidget::~AKirbyWidget()
{
}

void AKirbyWidget::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);


	APlayer* player = GetWorld()->GetPawn<APlayer>();
	//FVector2D CurPlayerPos = player->GetActorLocation();
	FVector2D CamPos = GetWorld()->GetCameraPos();
	//SetActorLocation({ CamPos.X ,CamPos.Y  });
	//SpriteRenderer->SetComponentLocation({ GetWorld()->GetCameraPos()});


	//Icon->SetComponentLocation(GetActorLocation());
	Icon->SetComponentLocation({ CamPos.X+WinSize.Half().X-150,CamPos.Y+WinSize.Y-60 });
	Life->SetComponentLocation({ CamPos.X+WinSize.Half().X-100,CamPos.Y+WinSize.Y-57 });
	HpBarCase->SetComponentLocation({ CamPos.X+ WinSize.Half().X-100,CamPos.Y+WinSize.Y-20 });
	NameTag->SetComponentLocation({ CamPos.X,CamPos.Y+WinSize.Y-5 });

}

void AKirbyWidget::BeginPlay()
{
	Icon->SetComponentLocation(GetWorld()->GetCameraPos());

}

