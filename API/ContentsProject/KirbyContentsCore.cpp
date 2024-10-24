#include "PreCompile.h"
#include "KirbyContentsCore.h"
#include <EngineCore/EngineAPICore.h>

#include "PlayGameMode.h"
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
	// �ƹ� ���� ���� �ڵ�.
	// �ִ� �Ե��� ��������Ѵ�.
	// TitleLevel = new ULevel();
	
	// ��ü�� �����ϴ� �Լ��� �������ִµ� �����ϸ� �ȵȴٴ°�.
	// �̰� ���ؼ� �ȸ��� �ֵ� => �� �ƹ��� ���� ���� ���ɼ��� ����.
	
	//UEngineAPICore::GetCore()->CreateLevel("Title");
	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");
	//UEngineAPICore::GetCore()->CreateLevel("End");

	UEngineAPICore::GetCore()->OpenLevel("Play");

}

void KirbyContentsCore::Tick()
{
}