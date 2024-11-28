#include "PreCompile.h"
#include "Stage1_1GameMode.h"
#include "StageBackground.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include <EnginePlatform/EngineSound.h>
#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "Monster.h"
#include "WaddleDee.h"
#include "WaddleDoo.h"
#include "Sparky.h"
#include "SoundManager.h"

#include "Stage1_1Map.h"

AStage1_1GameMode::AStage1_1GameMode()
{
	SetName("Stage1_1");
}

AStage1_1GameMode::~AStage1_1GameMode()
{
}
void AStage1_1GameMode::BeginPlay()
{
	Super::BeginPlay();


	{
		
		SoundManager& SoundManager = SoundManager::GetInst();
		USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // 레퍼런스 사용


		if (false == BGMPlayer.IsPlaying())
		{
			BGMPlayer = UEngineSound::Play("04. Prism Plains.mp3");
			BGMPlayer.Loop(1);

			SoundManager.SetSoundPlayer(BGMPlayer);
		}


		


	}
	AStageBackground* NewActor = GetWorld()->SpawnActor<AStageBackground>();
	AStage1_1Map* NewMap = GetWorld()->SpawnActor<AStage1_1Map>();
	APlayer* Player = GetWorld()->GetPawn<APlayer>();
	
	MonsterWaddleDee = GetWorld()->SpawnActor<AWaddleDee>();
	//AMonster* mon = GetWorld()->SpawnActor<AWaddleDee>();
	MonsterWaddleDoo = GetWorld()->SpawnActor<AWaddleDoo>();
	MonsterSparky = GetWorld()->SpawnActor<ASparky>();

	MonsterWaddleDee->SetActorLocation({ 1500, 300 });
	//mon->SetActorLocation({ 1000, 300 });
	MonsterWaddleDoo->SetActorLocation({ 3050, 50 });
	//MonsterWaddleDoo->SetActorLocation({ 1000, 50 });
	MonsterSparky->SetActorLocation({ 3400, 200 });

	/*MonsterWaddleDee->SetActive(false);
	MonsterWaddleDoo->SetActive(false);
	MonsterSparky->SetActive(false);*/
	
	Player->SetColImage("foreground1-1_col.png");

	MonsterWaddleDee->SetColImage("foreground1-1_col.png");
	//mon->SetColImage("foreground1-1_col.png");
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

