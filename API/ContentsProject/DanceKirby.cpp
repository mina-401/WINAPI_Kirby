#include "PreCompile.h"
#include "DanceKirby.h"
#include <EngineCore/ImageManager.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"

ADanceKirby::ADanceKirby()
{
	UImageManager::GetInst().CuttingSprite("KirbyDance.png", { 128, 128 });

	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	SpriteRenderer->SetComponentScale({ 270, 270 });
	SpriteRenderer->CreateAnimation("KirbyDance", "KirbyDance.png", 0, 29, 0.1f,false);
	SpriteRenderer->ChangeAnimation("KirbyDance");


}

ADanceKirby::~ADanceKirby()
{
}

void ADanceKirby::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->SetCameraToMainPawn(false);
}

void ADanceKirby::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == SpriteRenderer->IsCurAnimationEnd())
	{
		//if (IsEndDance == true) return;

		IsEndDance = true;
	}
}
void ADanceKirby::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void ADanceKirby::LevelChangeEnd()
{
	Super::LevelChangeEnd();
}

void ADanceKirby::SetColImage(std::string_view _ColImageName)
{

}
