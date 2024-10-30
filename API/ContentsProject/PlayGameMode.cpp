#include "PreCompile.h"
#include "PlayGameMode.h"

#include <EngineCore/Level.h>
#include "PlayMap.h"
APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

// 언리얼에서는 MainPawn 주인공 무조건 지정하게 해요.
void APlayGameMode::BeginPlay()
{
	APlayMap* PMAP0 = GetWorld()->SpawnActor<APlayMap>();
}
