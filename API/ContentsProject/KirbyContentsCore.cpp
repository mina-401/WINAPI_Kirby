#include "PreCompile.h"
#include "KirbyContentsCore.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>

#include "PlayGameMode.h"
#include "Stage1_1GameMode.h"
#include "Stage1_2GameMode.h"
#include "Stage1_3GameMode.h"
#include "Stage1_4GameMode.h"
#include "ItemRoomBeforeBossGameMode.h"
#include "StageBossKingDededeGameMode.h"

#include "TitleGameMode.h"
#include "Player.h"
KirbyContentsCore::KirbyContentsCore()
{
}

KirbyContentsCore::~KirbyContentsCore()
{
}

// ������ ����ǰ� �� 1�� ����ȴ�.
void KirbyContentsCore::BeginPlay()
{
	UEngineDirectory Dir;

	if (false == Dir.MoveParentToDirectory("Resource"))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}

	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();


	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UImageManager::GetInst().Load(FilePath);
	}

	UImageManager::GetInst().CuttingSprite("KirbyDance.png", { 128, 128 });

	{

		UEngineDirectory KirbyDir;
		KirbyDir.MoveParentToDirectory("Resource");
		KirbyDir.Append("PlayLevel");
		KirbyDir.Append("Kirby");
 		UImageManager::GetInst().LoadFolder(KirbyDir.GetPathToString());
	}
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("WinAPI_Kirby");
	// main window�� backbuffer
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, { 590, 440 });


	UEngineAPICore::GetCore()->CreateLevel<AStage1_1GameMode, APlayer>("Stage1_1");
	UEngineAPICore::GetCore()->CreateLevel<AStage1_2GameMode, APlayer>("Stage1_2");
	UEngineAPICore::GetCore()->CreateLevel<AStage1_3GameMode, APlayer>("Stage1_3");
	UEngineAPICore::GetCore()->CreateLevel<AStage1_4GameMode, APlayer>("Stage1_4");
	UEngineAPICore::GetCore()->CreateLevel<AItemRoomBeforeBossGameMode, APlayer>("ItemRoomBeforeBoss");
	UEngineAPICore::GetCore()->CreateLevel<AStageBossKingDededeGameMode, APlayer>("StageBossKingDedede");

	UEngineAPICore::GetCore()->CreateLevel<ATitleGameMode, AActor>("Title"); 

	UEngineAPICore::GetCore()->OpenLevel("Title");

}

void KirbyContentsCore::Tick()
{
}