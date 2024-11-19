#include "PreCompile.h"
#include "MonsterWidget.h"

#include "ContentsEnum.h"
#include "Player.h"

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
		UImageManager::GetInst().CuttingSprite("MonHp.png", { 183,17 });

		{
			MonHpBarCase = CreateDefaultSubObject<USpriteRenderer>();
			MonHpBarCase->SetOrder(ERenderOrder::UI);

			MonHpBarCase->SetSprite("MonHpBarCase.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

			MapScale = MonHpBarCase->SetSpriteScale(1.0f);

			MonHpBarCase->SetCameraEffect(false);
			//MonHpBarCase->SetActive(false);
		}
		{
			MonHp = CreateDefaultSubObject<USpriteRenderer>();
			MonHp->SetOrder(ERenderOrder::UI);

			MonHp->SetSprite("MonHp.png");

			WinSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();

			MapScale = MonHp->SetSpriteScale(1.0f);
			MonHp->SetCameraEffect(false);
			//MonHp->SetActive(false);
		}
	}
}

AMonsterWidget::~AMonsterWidget()
{
}

void AMonsterWidget::Tick(float _deltaTime)
{
}

void AMonsterWidget::BeginPlay()
{

	MonHpBarCase->SetComponentLocation({ WinSize.X - 150,WinSize.Y - 20 });
	MonHp->SetComponentLocation({ WinSize.X - 150,WinSize.Y - 20 });
}

