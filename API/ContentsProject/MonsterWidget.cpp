#include "PreCompile.h"
#include "MonsterWidget.h"

#include "ContentsEnum.h"
#include "Player.h"
#include "Monster.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>


AMonsterWidget::AMonsterWidget()
{
	DebugOn();
	{
		SetName("MonsterHp");
		
		UImageManager::GetInst().CuttingSprite("MonHpBarCase.png", { 230, 30 });
		UImageManager::GetInst().CuttingSprite("MonHp.png", { 1,16 });

		{
			MonHpBarCase = CreateDefaultSubObject<USpriteRenderer>();
			MonHpBarCase->SetOrder(ERenderOrder::UI);

			MonHpBarCase->SetSprite("MonHpBarCase.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

			MapScale = MonHpBarCase->SetSpriteScale(1.0f);

			MonHpBarCase->SetCameraEffect(false);
		}
		{
			MonHp = CreateDefaultSubObject<USpriteRenderer>();
			MonHp->SetOrder(ERenderOrder::UI);

			MonHp->SetSprite("MonHp.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

			MapScale = MonHp->SetSpriteScale(1.0f);
			MonHp->SetComponentScale(HpBarScale);

			MonHp->SetPivotValue({ 0.0,0.5f });
			MonHp->SetCameraEffect(false);
		}
	}
}

AMonsterWidget::~AMonsterWidget()
{
}

void AMonsterWidget::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);

	{

		bool IsDamaged = Owner->GetIsDamagedState();
	
		if (false == IsDamaged)
		{
			Owner->SetIsDamagedState(false);
			//Owner->Set
			TotalDamage = 0;
			return;
		}


		TotalDamage += 0.1f;

		float hp = Owner->GetCurHp() - 0.1f;
		if (hp <= 0)
		{
			IsDamaged = false;

		}
		if (TotalDamage >= DamagePower)
		{
			IsDamaged = false;
		}
			float HpRatio = hp / Owner->GetMaxHp();

			MonHp->SetComponentScale({ HpBarScale.X * HpRatio,HpBarScale.Y });
			Owner->SetCurHP(hp);
		


	}
}

void AMonsterWidget::BeginPlay()
{

	MonHpBarCase->SetComponentLocation({ WinSize.X - 150,WinSize.Y - 20 });
	MonHp->SetComponentLocation({ WinSize.X - 150- HpBarScale.Half().X,WinSize.Y - 20});

	SetDamagePower(100.0f);
}
