#include "PreCompile.h"
#include "PlayGameMode.h"

#include <EngineCore/Level.h>
#include "PlayMap.h"
#include "Player.h"

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

// �𸮾󿡼��� MainPawn ���ΰ� ������ �����ϰ� �ؿ�.
void APlayGameMode::BeginPlay()
{
	// �𸮾󿡼� ���� ���� 
	// ���� ��Ģ�� ���ϰ� ���ӿ� ���� ��Ģ�� �԰��� �غ��϶�� �𸮾��� �غ���
	// ���� ���� ��������ٴ� �� �� ��ü�� �߿��ϴ�.
	// ���� ��ü�� �غ��ų�� �ִ� �����̴�.

	// ���� ���� �������� ���Ӹ��
	// => ������ ��������� ������ ��������� �Ѵ�.
	// �������� �������� �Ұ��̴�.

	// �������� ������� ���Ӹ�忡��
	// BeginPlay�� �Ҷ� => �� ������ ���۵Ǹ� �����ؾ� �ϴ� ����
	// �÷��̾�� ���״�� �ֿ� ���� ���Ͷ�� �����ϰ� �ֱ� ������.
	// ������ ��������� ����������� ���͵��� ����� �뵵�� �������� �ʾ�.

	// GameMode =>�� ��ӹ޴� ���� ���� ���Ӹ�����
	// ������ �����Ҵ� �ʿ��� �͵��� �غ��϶�� ������� ���� ���� ���������
	// <= �ظ��ϸ� �ʹݿ� �� ����� ����.

	APlayer* Player = GetWorld()->GetPawn<APlayer>();
	Player->SetColImage("bg001_Col.png");

	int a = 0;

	{
		APlayMap* NewActor = GetWorld()->SpawnActor<APlayMap>();
	}
}
