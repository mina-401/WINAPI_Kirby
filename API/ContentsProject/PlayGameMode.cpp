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

// �𸮾󿡼��� MainPawn ���ΰ� ������ �����ϰ� �ؿ�.
void APlayGameMode::BeginPlay()
{
	APlayMap* PMAP0 = GetWorld()->SpawnActor<APlayMap>();
}
