#pragma once
#include <list>
#include <vector>
#include <map>
#include <string>

#include <EnginePlatform/EngineWinImage.h>
#include "EngineSprite.h"

// ���� :
class UImageManager
{
public:
	// constrcuter destructer
	~UImageManager();

	// delete Function
	UImageManager(const UImageManager& _Other) = delete;
	UImageManager(UImageManager&& _Other) noexcept = delete;
	UImageManager& operator=(const UImageManager& _Other) = delete;
	UImageManager& operator=(UImageManager&& _Other) noexcept = delete;

	static UImageManager& GetInst()
	{
		static UImageManager Inst;
		return Inst;
	}

	// ��θ� ��ä�� �־��ָ� �ڵ����� ���ϸ��� Ű������ �ɰ̴ϴ�.
	// ���Ǽ� �Լ�
	void Load(std::string_view Path);

	// ������ �װ� �̹����� �ε��ϰ� ã����
	// �����ε�� ���⿡�� ó��
	void Load(std::string_view _KeyName, std::string_view Path);


	// void LoadDirectory(std::string_view _KeyName, std::string_view Path);

protected:

private:
	UImageManager();

	// UEngineWinImage*
	// �ִϸ��̼� �̶� ����?
	// �������� �������� ���ư��°�.
	// UEngineWinImage* �̰� �ɰ��� 
	std::map<std::string, UEngineWinImage*> Images;

	std::map<std::string, UEngineSprite*> Sprites;
};

