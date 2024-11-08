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
		
			UImageManager::GetInst().CuttingSprite("LifeIcon.png", { 55, 30 });
			UImageManager::GetInst().CuttingSprite("Font1.png", { 42, 26 });
			UImageManager::GetInst().CuttingSprite("Font2.png", { 45, 26 });
			UImageManager::GetInst().CuttingSprite("Font3.png", { 44, 26 });
			UImageManager::GetInst().CuttingSprite("KirbyHpBarCase.png", { 215, 30 });
			UImageManager::GetInst().CuttingSprite("KirbyHp.png", { 183, 21 });
			UImageManager::GetInst().CuttingSprite("nametag_normal.png", { 214, 190 });
		
		{
			Icon = CreateDefaultSubObject<USpriteRenderer>();
			Icon->SetOrder(ERenderOrder::UI);

			Icon->SetSprite("LifeIcon.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

			MapScale = Icon->SetSpriteScale(1.0f);
		}

		{
			Life = CreateDefaultSubObject<USpriteRenderer>();
			Life->SetOrder(ERenderOrder::UI);

			Life->SetSprite("Font2.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

			MapScale = Life->SetSpriteScale(1.0f);
		} 
		{
			HpBarCase = CreateDefaultSubObject<USpriteRenderer>();
			HpBarCase->SetOrder(ERenderOrder::UI);

			HpBarCase->SetSprite("KirbyHpBarCase.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
			MapScale = HpBarCase->SetSpriteScale(1.0f);
		}
		{
			HpBar = CreateDefaultSubObject<USpriteRenderer>();
			HpBar->SetOrder(ERenderOrder::UI);

			HpBar->SetSprite("KirbyHp.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
			MapScale = HpBar->SetSpriteScale(1.0f);
		}
		{
			NameTag = CreateDefaultSubObject<USpriteRenderer>();
			NameTag->SetOrder(ERenderOrder::UI);

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

	FVector2D CamPos = GetWorld()->GetCameraPos();
	SetActorLocation({ CamPos.X ,CamPos.Y  });
	Icon->SetComponentLocation({ WinSize.Half().X-150,WinSize.Y-60 });
	Life->SetComponentLocation({ WinSize.Half().X-90,WinSize.Y-57 });
	HpBarCase->SetComponentLocation({WinSize.Half().X-100,WinSize.Y-20 });
	HpBar->SetComponentLocation({WinSize.Half().X-100,WinSize.Y-20 });
	NameTag->SetComponentLocation({(float) 0,WinSize.Y-5 });

}

void AKirbyWidget::BeginPlay()
{
	Super::BeginPlay();

}

