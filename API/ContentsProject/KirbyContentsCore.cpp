#include "PreCompile.h"
#include "KirbyContentsCore.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineSound.h>

#include "Stage1_1GameMode.h"
#include "Stage1_2GameMode.h"
#include "Stage1_3GameMode.h"
#include "Stage1_4GameMode.h"
#include "ItemRoomBeforeBossGameMode.h"
#include "StageBossKingDededeGameMode.h"
#include "ContentsEnum.h"
#include "TitleGameMode.h"
#include "Player.h"
#include "DanceKirby.h"
#include "EndingGameMode.h"
KirbyContentsCore::KirbyContentsCore()
{
}

KirbyContentsCore::~KirbyContentsCore()
{
}

// ������ ����ǰ� �� 1�� ����ȴ�.
void KirbyContentsCore::BeginPlay()
{

	{
		// Init Window Pos, Scale
		int width = GetSystemMetrics(SM_CXSCREEN);
		int height = GetSystemMetrics(SM_CYSCREEN);
		//UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("VVVVVV");
		FVector2D WindowResolution = FVector2D(width, height);
		FVector2D InitWindowScale = FVector2D(640, 440);//{ 640, 440 }
		UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale(WindowResolution.Half() - InitWindowScale.Half(), InitWindowScale);

		// Debug Pen, Brush Setting : Black Solid Pen, Hollow Brush
		UEngineWinImage* BackBufferImage = UEngineAPICore::GetCore()->GetMainWindow().GetBackBuffer();
		HBRUSH OldBrush = static_cast<HBRUSH>(SelectObject(BackBufferImage->GetDC(), GetStockObject(NULL_BRUSH)));
		HPEN OldPen = static_cast<HPEN>(SelectObject(BackBufferImage->GetDC(), GetStockObject(BLACK_PEN)));
		DeleteObject(OldBrush);
		DeleteObject(OldPen);
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resource"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UImageManager::GetInst().Load(FilePath);
		}
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resource"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Sound//Stage1Sound");
		std::vector<UEngineFile> SoundFiles = Dir.GetAllFile();
		for (size_t i = 0; i < SoundFiles.size(); i++)
		{
			std::string FilePath = SoundFiles[i].GetPathToString();
			UEngineSound::Load(FilePath);
		}
	}
	
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resource"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Sound//BossSound");
		std::vector<UEngineFile> SoundFiles = Dir.GetAllFile();
		for (size_t i = 0; i < SoundFiles.size(); i++)
		{
			std::string FilePath = SoundFiles[i].GetPathToString();
			UEngineSound::Load(FilePath);
		}
	}
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resource"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Sound//TitleSound");
		std::vector<UEngineFile> SoundFiles = Dir.GetAllFile();
		for (size_t i = 0; i < SoundFiles.size(); i++)
		{
			std::string FilePath = SoundFiles[i].GetPathToString();
			UEngineSound::Load(FilePath);
		}
	}
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resource"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Sound//EffectSound");
		std::vector<UEngineFile> SoundFiles = Dir.GetAllFile();
		for (size_t i = 0; i < SoundFiles.size(); i++)
		{
			std::string FilePath = SoundFiles[i].GetPathToString();
			UEngineSound::Load(FilePath);
		}
	}
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resource"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Sound//EndingSound");
		std::vector<UEngineFile> SoundFiles = Dir.GetAllFile();
		for (size_t i = 0; i < SoundFiles.size(); i++)
		{
			std::string FilePath = SoundFiles[i].GetPathToString();
			UEngineSound::Load(FilePath);
		}
	}

	{
		UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("WinAPI_Kirby");

		UEngineAPICore::GetCore()->CreateLevel<ATitleGameMode, AActor>("Title");

		UEngineAPICore::GetCore()->CreateLevel<AStage1_1GameMode, APlayer>("Stage1_1");
		UEngineAPICore::GetCore()->CreateLevel<AStage1_2GameMode, APlayer>("Stage1_2");
		UEngineAPICore::GetCore()->CreateLevel<AStage1_3GameMode, APlayer>("Stage1_3");
		//UEngineAPICore::GetCore()->CreateLevel<AStage1_4GameMode, APlayer>("Stage1_4");
		UEngineAPICore::GetCore()->CreateLevel<AItemRoomBeforeBossGameMode, APlayer>("ItemRoomBeforeBoss");
		UEngineAPICore::GetCore()->CreateLevel<AStageBossKingDededeGameMode, APlayer>("StageBossKingDedede");
		UEngineAPICore::GetCore()->CreateLevel<AEndingGameMode, ADanceKirby>("Stage_DanceEnding");

		ULevel::CollisionGroupLink(ECollisionGroup::MonsterAttack, ECollisionGroup::PlayerBody);
		ULevel::CollisionGroupLink(ECollisionGroup::Block, ECollisionGroup::MonsterBody);
		ULevel::CollisionGroupLink(ECollisionGroup::Block, ECollisionGroup::PlayerBody);
		ULevel::CollisionGroupLink(ECollisionGroup::PlayerBody, ECollisionGroup::MonsterBody);
		ULevel::CollisionGroupLink(ECollisionGroup::PlayerBody, ECollisionGroup::Block);
		ULevel::CollisionGroupLink(ECollisionGroup::MonsterBody, ECollisionGroup::PlayerInhaleRange);
		ULevel::CollisionGroupLink(ECollisionGroup::Potal, ECollisionGroup::PlayerBody);


		UEngineAPICore::GetCore()->OpenLevel("Title");
	}
}

void KirbyContentsCore::Tick()
{
}