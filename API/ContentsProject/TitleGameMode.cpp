#include "PreCompile.h"
#include "TitleGameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "TitleLogo.h"
#include <EnginePlatform/EngineSound.h>
#include "SoundManager.h"


ATitleGameMode::ATitleGameMode()
{
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();
	TitleLogo* NewActor = GetWorld()->SpawnActor<TitleLogo>();

	/*{
		BGMPlayer = UEngineSound::Play("01. Ttile Screen.mp3");
		BGMPlayer.Loop(1);

	}*/
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SoundManager& SoundManager = SoundManager::GetInst();
	USoundPlayer& BGMPlayer = SoundManager.GetSoundPlayer(); // ���۷��� ���
	if( false ==BGMPlayer.IsPlaying())
	{
		BGMPlayer = UEngineSound::Play("01. Ttile Screen.mp3");

		SoundManager.SetSoundPlayer(BGMPlayer);
	}

		

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		BGMPlayer.Stop();
		UEngineAPICore::GetCore()->OpenLevel("Stage1_1");
	}

}

