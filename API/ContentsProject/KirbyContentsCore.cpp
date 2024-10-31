#include "PreCompile.h"
#include "KirbyContentsCore.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>

#include "PlayGameMode.h"
#include "TitleGameMode.h"
#include "Player.h"
#include "Camera.h"

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
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, { 1280, 720 });


	UEngineAPICore::GetCore()->CreateLevel<ATitleGameMode, ACamera>("Title"); 
	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");

	UEngineAPICore::GetCore()->OpenLevel("Play");

}

void KirbyContentsCore::Tick()
{
}