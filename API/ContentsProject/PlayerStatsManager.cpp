#include "PreCompile.h"
#include "PlayerStatsManager.h"
#include <EngineCore/ImageManager.h>



PlayerStatsManager::PlayerStatsManager()
{
	Life = 2;
	Hp = 100.0f;
	PlayerStats = ECopyAbilityState::Normal;

	
}

PlayerStatsManager::~PlayerStatsManager()
{
}

