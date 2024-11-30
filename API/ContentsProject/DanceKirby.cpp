#include "PreCompile.h"
#include "DanceKirby.h"

ADanceKirby::ADanceKirby()
{
}

ADanceKirby::~ADanceKirby()
{
}

void ADanceKirby::BeginPlay()
{
	Super::BeginPlay();
}

void ADanceKirby::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
void ADanceKirby::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void ADanceKirby::LevelChangeEnd()
{
	Super::LevelChangeEnd();
}

void ADanceKirby::SetColImage(std::string_view _ColImageName)
{

}
