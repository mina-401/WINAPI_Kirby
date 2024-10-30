#include "PreCompile.h"
#include "Camera.h"
#include "EngineCore/EngineAPICore.h"
#include <EnginePlatform/EngineInput.h>

ACamera::ACamera()
{
}

ACamera::~ACamera()
{
}

void ACamera::BeginPlay()
{
	//UEngineAPICore::GetCore()->GetMainWindow().

	UEngineInput::GetInst().BindAction(VK_LBUTTON, KeyEvent::Press, std::bind(&ACamera::ClickFunction, this, VK_LBUTTON));
}

void ACamera::Tick(float _DeltaTime)
{
}

void ACamera::ClickFunction(int _KeyIndex)
{
	switch (_KeyIndex)
	{
	case VK_LBUTTON:
		//MoveFunction(FVector2D::RIGHT);

		break;
	default:
		break;
	}
}
