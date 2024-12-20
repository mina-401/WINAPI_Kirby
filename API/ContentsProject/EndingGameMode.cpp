#include "PreCompile.h"
#include "EndingGameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineSound.h>
#include <EngineCore/EngineAPICore.h>
#include "DanceKirby.h"
#include "EndingMap.h"
#include "Fade.h"
#include "SoundManager.h"
#include "TitleGameMode.h"
#include "Player.h"

AEndingGameMode::AEndingGameMode()
{
}

AEndingGameMode::~AEndingGameMode()
{
}
//ending_background_map

void AEndingGameMode::BeginPlay()
{
	Super::BeginPlay();
	{

		SoundManager& SoundManager = SoundManager::GetInst();
		USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // ���۷��� ���

		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}
		BGMPlayer = UEngineSound::Play("06. Kirby Dance (Short).mp3");

		SoundManager.SetSoundPlayer(BGMPlayer);


	}
	{
		//player->SetActorLocation({ MapScale.Half().X,MapScale.Half().Y + 76 });
	}
	

//	player->SetColImage("foregroundKingDedede1-1_col.png");
	AEndingMap* NewActor = GetWorld()->SpawnActor<AEndingMap>();

}

void AEndingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ADanceKirby* player = GetWorld()->GetPawn<ADanceKirby>();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE) && player->IsEndDance)
	{
		SoundManager& SoundManager = SoundManager::GetInst();
		USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // ���۷��� ���

		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}

		SoundManager.SetSoundPlayer(BGMPlayer);
		//UEngineAPICore::GetCore()->ResetLevel<ATitleGameMode, APlayer>("Title");
		UEngineAPICore::GetCore()->OpenLevel("Title");


	}




	
	if (Actor != nullptr && 2 <= Actor->FadeValue)
	{
		Actor->FadeOut(2);
	}
	if (true == player->IsEndDance)
	{
		if (Actor != nullptr) return;
			SoundManager& SoundManager = SoundManager::GetInst();
		USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // ���۷��� ���

		if (true == BGMPlayer.IsPlaying())
		{
			BGMPlayer.Stop();
		}
		BGMPlayer = UEngineSound::Play("05. Victory Star.mp3");

		SoundManager.SetSoundPlayer(BGMPlayer);

		{
			Actor = GetWorld()->SpawnActor<AFade>();
			Actor->FadeIn(2);

		}
	}
}