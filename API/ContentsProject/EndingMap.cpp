#include "PreCompile.h"
#include "EndingMap.h"
#include "Player.h"
#include <EnginePlatform/EngineInput.h>

AEndingMap::AEndingMap()
{
}

AEndingMap::~AEndingMap()
{
}
void AEndingMap::BeginPlay()
{
	Super::BeginPlay();
	APlayer* player = GetWorld()->GetPawn<APlayer>();
	player->SetActorLocation({ 300,300 });

}

void AEndingMap::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);


}
