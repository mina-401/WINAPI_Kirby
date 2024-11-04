#pragma once
#include <EngineCore/Level.h>

// Ό³Έν :
class KirbyLevel : public ULevel
{
public:
	// constrcuter destructer
	KirbyLevel();
	~KirbyLevel();

	// delete Function
	KirbyLevel(const KirbyLevel& _Other) = delete;
	KirbyLevel(KirbyLevel&& _Other) noexcept = delete;
	KirbyLevel& operator=(const KirbyLevel& _Other) = delete;
	KirbyLevel& operator=(KirbyLevel&& _Other) noexcept = delete;

protected:

private:

};

