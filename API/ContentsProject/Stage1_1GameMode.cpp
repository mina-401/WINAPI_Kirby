#include "PreCompile.h"
#include "Stage1_1GameMode.h"
#include "StageBackground.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "Monster.h"
#include "WaddleDee.h"
#include "WaddleDoo.h"
#include "Sparky.h"


#include "Stage1_1Map.h"
AStage1_1GameMode::AStage1_1GameMode()
{
}

AStage1_1GameMode::~AStage1_1GameMode()
{
}
void AStage1_1GameMode::BeginPlay()
{
	Super::BeginPlay();



	AStageBackground* NewActor = GetWorld()->SpawnActor<AStageBackground>();
	AStage1_1Map* NewMap = GetWorld()->SpawnActor<AStage1_1Map>();
	APlayer* Player = GetWorld()->GetPawn<APlayer>();
	
	MonsterWaddleDee = GetWorld()->SpawnActor<AWaddleDee>();
	MonsterWaddleDoo = GetWorld()->SpawnActor<AWaddleDoo>();
	MonsterSparky = GetWorld()->SpawnActor<ASparky>();

	MonsterWaddleDee->SetActorLocation({ 1500, 300 });
	MonsterWaddleDoo->SetActorLocation({ 3050, 50 });
	MonsterSparky->SetActorLocation({ 3400, 200 });

	/*MonsterWaddleDee->SetActive(false);
	MonsterWaddleDoo->SetActive(false);
	MonsterSparky->SetActive(false);*/
	
	Player->SetColImage("foreground1-1_col.png");
	MonsterWaddleDee->SetColImage("foreground1-1_col.png");
	MonsterWaddleDoo->SetColImage("foreground1-1_col.png");
	MonsterSparky->SetColImage("foreground1-1_col.png");

}

void AStage1_1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('P'))
	{
		UEngineAPICore::GetCore()->OpenLevel("Stage1_2");
	}
	 
}

