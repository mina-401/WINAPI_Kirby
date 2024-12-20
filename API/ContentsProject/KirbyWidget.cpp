#include "PreCompile.h"
#include "KirbyWidget.h"
#include "ContentsEnum.h"
#include "Player.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>


#include "PlayerStatsManager.h"

AKirbyWidget::AKirbyWidget()
{
	DebugOn();
	{
		SetName("MainHud");
		
		UImageManager::GetInst().CuttingSprite("LifeIcon.png", { 55, 30 });
		UImageManager::GetInst().CuttingSprite("Font0.png", { 43, 26 });
		UImageManager::GetInst().CuttingSprite("Font1.png", { 41, 26 });
		UImageManager::GetInst().CuttingSprite("Font2.png", { 45, 26 });
	//	UImageManager::GetInst().CuttingSprite("Font3.png", { 44, 26 });
		UImageManager::GetInst().CuttingSprite("KirbyHpBarCase.png", { 215, 30 });
		UImageManager::GetInst().CuttingSprite("HpBar.png", { 1, 21 });
		UImageManager::GetInst().CuttingSprite("nametag_normal.png", { 214, 190 });
		//UImageManager::GetInst().CuttingSprite("nametag_beam.png", { 214, 190 });
		UImageManager::GetInst().CuttingSprite("nametag_fire.png", { 214, 190 });
		UImageManager::GetInst().CuttingSprite("nametag_spark.png", { 214, 190 });
		
		WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
		{
			Icon = CreateDefaultSubObject<USpriteRenderer>();
			Icon->SetCameraEffect(false);
			Icon->SetOrder(ERenderOrder::UI);
			Icon->SetSprite("LifeIcon.png");
			MapScale = Icon->SetSpriteScale(1.0f);
		}

		{
			Life = CreateDefaultSubObject<USpriteRenderer>();
			Life->SetCameraEffect(false);
			Life->SetOrder(ERenderOrder::UI);
			Life->SetSprite("Font2.png");
			MapScale = Life->SetSpriteScale(1.0f);
		} 
		{
			HpBarCase = CreateDefaultSubObject<USpriteRenderer>();
			HpBarCase->SetCameraEffect(false);
			HpBarCase->SetOrder(ERenderOrder::UI);
			HpBarCase->SetSprite("KirbyHpBarCase.png");
			MapScale = HpBarCase->SetSpriteScale(1.0f);
		}
		{
			HpBar = CreateDefaultSubObject<USpriteRenderer>();
			HpBar->SetCameraEffect(false);
			HpBar->SetOrder(ERenderOrder::UI);
			HpBar->SetSprite("HpBar.png");
			MapScale = HpBar->SetSpriteScale(1.0f);
			HpBar->SetComponentScale(HpBarScale);
			HpBar->SetPivotValue({ 0.0f,0.5f }); 
		}
		{
			NameTag = CreateDefaultSubObject<USpriteRenderer>();
			NameTag->SetCameraEffect(false);
			NameTag->SetOrder(ERenderOrder::UI);
			NameTag->SetSprite("nametag_normal.png");
			MapScale = NameTag->SetSpriteScale(1.0f);
		}
		{
			
		}
	}
}

AKirbyWidget::~AKirbyWidget()
{
}

void AKirbyWidget::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	int CurLife = Owner->GetCurLife();
	ECopyAbilityState Copy = Owner->GetCurPlayerCopyState();
	{
		

		switch (Copy)
		{
		case ECopyAbilityState::Normal:
			NameTag->SetSprite("nametag_normal.png");
			break;
		case ECopyAbilityState::Fire:
			NameTag->SetSprite("nametag_fire.png");
			break;
		case ECopyAbilityState::Spark:
			NameTag->SetSprite("nametag_spark.png");
			break;
		case ECopyAbilityState::Beam:
			NameTag->SetSprite("nametag_beam.png");
			break;
		default:
			break;
		}

		switch (CurLife)
		{
		case 3:
			Life->SetSprite("Font2.png");
			break;
		case 4:
			//Life->SetSprite("Font3.png");
			break;
		case 2:
			Life->SetSprite("Font1.png");
			break;
		case 1:
			Life->SetSprite("Font0.png");
			break;
		default:
			Life->SetSprite("Font0.png");
			break;
		}
	}
	{

	}
	{
	
		float hp = Owner->GetCurHp();
		float HpRatio = hp / Owner->GetMaxHp();
		HpBar->SetComponentScale({ HpBarScale.X * HpRatio,HpBarScale.Y });
		

		bool IsDamaged = Owner->GetIsDamagedState();

		

		if (true == IsDamaged)
		{
			

			TotalDamage += 0.1f;
			hp = Owner->GetCurHp() - 0.1f;
			if (hp <= 0)
			{
				

				IsDamaged = false;

			}
			if (TotalDamage >= Owner->GetDamagePower())
			{
				IsDamaged = false;
			}

		}

		if (false == IsDamaged)
		{
			Owner->SetIsDamagedState(false);
			TotalDamage = 0;

		}
		
		Owner->SetCurHP(hp);

		
		
		/*if (0 < CurLife &&  0 >= hp)
		{
			Owner->SetCurHP(Owner->GetMaxHp());
			Owner->SetCurLife(Owner->GetCurLife() - 1);
		}*/
		
	}
	
	{

	}

}

void AKirbyWidget::BeginPlay()
{
	Super::BeginPlay();
	/*{
		Score = GetWorld()->SpawnActor<AScore>();
		Score->SetActorLocation({300, 300});
		Score->SetTextSpriteName("Text.bmp");
		Score->SetOrder(ERenderOrder::UI);
		Score->SetTextScale({50, 100});
		Score->SetValue(45362784);
	}*/

	Icon->SetComponentLocation({ WinSize.Half().X - 150,WinSize.Y - 60 });
	Life->SetComponentLocation({ WinSize.Half().X - 90,WinSize.Y - 57 });
	HpBarCase->SetComponentLocation({ WinSize.Half().X - 100,WinSize.Y - 20 });
	HpBar->SetComponentLocation({ WinSize.Half().X - 100-HpBarScale.Half().X,WinSize.Y - 20});
	NameTag->SetComponentLocation({ (float)0,WinSize.Y - 5 });
}

