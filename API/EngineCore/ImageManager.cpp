#include "PreCompile.h"
#include "ImageManager.h"

#include <EngineBase/EnginePath.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineString.h>
#include <EngineBase/EngineFile.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineAPICore.h>

UImageManager::UImageManager()
{
}

UImageManager::~UImageManager()
{
	{
		std::map<std::string, UEngineWinImage*>::iterator StartIter = Images.begin();
		std::map<std::string, UEngineWinImage*>::iterator EndIter = Images.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			UEngineWinImage* CurRes = StartIter->second;
			if (nullptr != CurRes)
			{
				delete CurRes;
				CurRes = nullptr;
			}
		}
	}

	{
		std::map<std::string, UEngineSprite*>::iterator StartIter = Sprites.begin();
		std::map<std::string, UEngineSprite*>::iterator EndIter = Sprites.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			UEngineSprite* CurRes = StartIter->second;
			if (nullptr != CurRes)
			{
				delete CurRes;
				CurRes = nullptr;
			}
		}
	}
}


void UImageManager::Load(std::string_view Path)
{
	UEnginePath EnginePath = UEnginePath(Path);

	std::string FileName = EnginePath.GetFileName();

	Load(FileName, Path);
}

void UImageManager::LoadFolder(std::string_view Path)
{
	UEnginePath EnginePath = UEnginePath(Path);

	std::string DirName = EnginePath.GetDirectoryName();

	LoadFolder(DirName, Path);
}


void UImageManager::Load(std::string_view _KeyName, std::string_view Path)
{
	UEnginePath EnginePath = UEnginePath(Path);

	if (true == EnginePath.IsDirectory())
	{
		MSGASSERT("���丮�� �ε��Ҽ� �����ϴ�." + std::string(Path));
		return;
	}

	if (false == EnginePath.IsExists())
	{
		MSGASSERT("��ȿ���� ���� ���� ��� �Դϴ�." + std::string(Path));
		return;
	}

	UEngineWinImage* WindowImage = UEngineAPICore::GetCore()->GetMainWindow().GetWindowImage();

	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (true == Images.contains(UpperName))
	{
		MSGASSERT("�ε�� �̹����� �� �ε��� �� �����ϴ�." + UpperName);
		return;
	}

	if (true == Sprites.contains(UpperName))
	{
		MSGASSERT("�ε�� �̹����� �� �ε��� �� �����ϴ�." + UpperName);
		return;
	}

	// ������ٰ� ���� �ƴմϴ�.
	UEngineWinImage* NewImage = new UEngineWinImage();
	NewImage->Load(WindowImage, Path);
	NewImage->SetName(UpperName);
	Images.insert({ UpperName , NewImage });

	UEngineSprite* NewSprite = new UEngineSprite();

	// �̹����� �ڸ��� ������ �Ǵ� ��ġ�� ���� ���� �������� �ڸ��� ���� �ϰڴ�.
	FTransform Trans;
	Trans.Location = { 0,0 };
	Trans.Scale = NewImage->GetImageScale();
	NewSprite->PushData(NewImage, Trans);

	NewSprite->SetName(UpperName);
	Sprites.insert({ UpperName , NewSprite });
}

void UImageManager::LoadFolder(std::string_view _KeyName, std::string_view _Path)
{
	UEnginePath EnginePath = UEnginePath(_Path);

	if (false == EnginePath.IsExists())
	{
		MSGASSERT("��ȿ���� ���� ���� ��� �Դϴ�." + std::string(_Path));
		return;
	}

	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (true == Sprites.contains(UpperName))
	{
		MSGASSERT("�ε�� �̹����� �� �ε��� �� �����ϴ�." + UpperName);
		return;
	}


	UEngineSprite* NewSprite = new UEngineSprite();
	NewSprite->SetName(UpperName);
	Sprites.insert({ UpperName , NewSprite });

	// �ε��ϱ� ���ؼ� �ʿ��� Window Main HDC
	UEngineWinImage* WindowImage = UEngineAPICore::GetCore()->GetMainWindow().GetWindowImage();

	UEngineDirectory Dir = _Path;
	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();
	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		std::string UpperFileName = UEngineString::ToUpper(ImageFiles[i].GetFileName());

		UEngineWinImage* NewImage = FindImage(UpperFileName);
		if (nullptr == NewImage)
		{
			NewImage = new UEngineWinImage();
			NewImage->SetName(UpperFileName);
			NewImage->Load(WindowImage, FilePath);
		}
		Images.insert({ UpperFileName,  NewImage });
		// �̹��� �ε��� ��������

		FTransform Transform;
		Transform.Location = { 0, 0 };
		Transform.Scale = NewImage->GetImageScale();

		NewSprite->PushData(NewImage, Transform);
	}
}

void UImageManager::CuttingSprite(std::string_view _KeyName, int _X, int _Y)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (false == Sprites.contains(UpperName))
	{
		MSGASSERT("�������� ���� ��������Ʈ�� �ڸ����� �߽��ϴ�" + std::string(_KeyName));
		return;
	}

	if (false == Images.contains(UpperName))
	{
		MSGASSERT("�������� ���� �̹����� ������� ��������Ʈ�� �ڸ����� �߽��ϴ�" + std::string(_KeyName));
		return;
	}

	UEngineSprite* Sprite = Sprites[UpperName];
	UEngineWinImage* Image = Images[UpperName];

	Sprite->ClearSpriteData();

	FVector2D Scale = Image->GetImageScale();

	Scale.X /= _X;
	Scale.Y /= _Y;

	CuttingSprite(_KeyName, Scale);
}

void UImageManager::CuttingSprite(std::string_view _KeyName, FVector2D _CuttingSize)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (false == Sprites.contains(UpperName))
	{
		MSGASSERT("�������� ���� ��������Ʈ�� �ڸ����� �߽��ϴ�" + std::string(_KeyName));
		return;
	}

	if (false == Images.contains(UpperName))
	{
		MSGASSERT("�������� ���� �̹����� ������� ��������Ʈ�� �ڸ����� �߽��ϴ�" + std::string(_KeyName));
		return;
	}

	UEngineSprite* Sprite = Sprites[UpperName];
	UEngineWinImage* Image = Images[UpperName];

	Sprite->ClearSpriteData();
	Sprite->SetName(UpperName);
	Image->SetName(UpperName);

	if (0 != (Image->GetImageScale().iX() % _CuttingSize.iX()))
	{
		MSGASSERT("��������Ʈ ���ÿ� x�� �� �������� �ʽ��ϴ�." + std::string(_KeyName));
		return;
	}

	if (0 != (Image->GetImageScale().iY() % _CuttingSize.iY()))
	{
		MSGASSERT("��������Ʈ ���ÿ� y�� �� �������� �ʽ��ϴ�." + std::string(_KeyName));
		return;
	}

	int SpriteX = Image->GetImageScale().iX() / _CuttingSize.iX();
	int SpriteY = Image->GetImageScale().iY() / _CuttingSize.iY();

	FTransform CuttingTrans;

	CuttingTrans.Location = FVector2D::ZERO;
	CuttingTrans.Scale = _CuttingSize;

	for (size_t y = 0; y < SpriteY; ++y)
	{
		for (size_t x = 0; x < SpriteX; ++x)
		{
			Sprite->PushData(Image, CuttingTrans);
			CuttingTrans.Location.X += _CuttingSize.X;
		}

		CuttingTrans.Location.X = 0.0f;
		CuttingTrans.Location.Y += _CuttingSize.Y;
	}
}

bool UImageManager::IsLoadSprite(std::string_view _KeyName)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	return Sprites.contains(UpperName);
}

UEngineSprite* UImageManager::FindSprite(std::string_view _KeyName)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (false == Sprites.contains(UpperName))
	{
		MSGASSERT("�ε����� ���� ��������Ʈ�� ����Ϸ��� �߽��ϴ�" + std::string(_KeyName));
		return nullptr;
	}

	//std::map<std::string, UEngineSprite*>::iterator FindIter = Sprites.find(UpperName);

	// �̰ɷ� 
	return Sprites[UpperName];
}

UEngineWinImage* UImageManager::FindImage(std::string_view _KeyName)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (false == Images.contains(UpperName))
	{
		// MSGASSERT("�ε����� ���� ��������Ʈ�� ����Ϸ��� �߽��ϴ�" + std::string(_KeyName));
		return nullptr;
	}

	// �̰ɷ� 
	return Images[UpperName];
}

// ������ �̹����� ã�� �߶� �� ���ο� ��������Ʈ �̹����� ����ϴ�.
// _NewSpriteKeyName : ���ο� Ű ��
// _StartPos : ���� �̹������� �߶� �»�� ��
// _CuttingSize : �̹��� ������
// _XYOffSet : �̹��� ������ ����� ����, XY
// _Xcount : ���� �̹��� ����
// _ImageCount : �� �̹��� ����
void UImageManager::CreateCutSprite(std::string_view _SearchKeyName, std::string_view _NewSpriteKeyName, FVector2D _StartPos, FVector2D _CuttingSize, FVector2D _XYOffSet, UINT _Xcount, UINT _ImageCount)
{
	std::string SearchName = UEngineString::ToUpper(_SearchKeyName);
	std::string NewSpriteName = UEngineString::ToUpper(_NewSpriteKeyName);

	if (_Xcount <= 0)
	{
		MSGASSERT("�̹����� ���� ������ 0 �����Դϴ�.");
		return;
	}
	if (_ImageCount <= 0)
	{
		MSGASSERT("�� �̹��� ������ 0 �����Դϴ�.");
		return;
	}
	if (Sprites.contains(SearchName) == false)
	{
		MSGASSERT(std::string(_SearchKeyName) + "��� �̸��� Sprite�� �ε��� �� �����ϴ�.");
		return;
	}
	if (Images.contains(SearchName) == false)
	{
		MSGASSERT(std::string(_SearchKeyName) + "��� �̸��� Sprite�� �ε��� �� �����ϴ�.");
		return;
	}
	if (Sprites.contains(NewSpriteName) == true)
	{
		MSGASSERT(std::string(_NewSpriteKeyName) + "��� �̸��� Sprite�� �̹� �����մϴ�.");
		return;
	}
	if (Images.contains(NewSpriteName) == true)
	{
		MSGASSERT(std::string(_NewSpriteKeyName) + "��� �̸��� Image�� �̹� �����մϴ�.");
		return;
	}


	UEngineSprite* Sprite = Sprites[SearchName];
	UEngineWinImage* Image = Images[SearchName];
	Sprite->SetName(SearchName);
	Image->SetName(SearchName);

	Sprite->ClearSpriteData();

	UINT YCount = _ImageCount / _Xcount;
	if (_ImageCount % _Xcount > 0)
		++YCount;

	float TotalSizeX = _StartPos.X + (_CuttingSize.X * _Xcount) + (_XYOffSet.X * (_Xcount - 1));
	float TotalSizeY = _StartPos.Y + (_CuttingSize.Y * YCount) + (_XYOffSet.Y * (YCount - 1));

	if (TotalSizeX > Image->GetImageScale().X)
	{
		MSGASSERT("�ʿ��� �̹��� ���� ����� ���� �̹��� ������� Ů�ϴ�.");
		return;
	}
	if (TotalSizeY > Image->GetImageScale().Y)
	{
		MSGASSERT("�ʿ��� �̹��� ���� ����� ���� �̹��� ������� Ů�ϴ�.");
		return;
	}

	FVector2D TotalSize = FVector2D(static_cast<int>(TotalSizeX), static_cast<int>(TotalSizeY));


	UEngineWinImage* NewImage = new UEngineWinImage();
	UEngineSprite* NewSprite = new UEngineSprite();
	NewImage->Create(UEngineAPICore::GetCore()->GetMainWindow().GetWindowImage(), TotalSize);

	BitBlt(NewImage->GetDC(), 0, 0, static_cast<int>(TotalSizeX), static_cast<int>(TotalSizeY), Image->GetDC(), static_cast<int>(_StartPos.X), static_cast<int>(_StartPos.Y), SRCCOPY);

	Images.insert(make_pair(NewSpriteName, NewImage));
	Sprites.insert(make_pair(NewSpriteName, NewSprite));

	FVector2D CuttingPos = {};

	for (UINT y = 0; y < YCount; ++y)
	{
		CuttingPos.Y = _CuttingSize.Y * y + _XYOffSet.Y * y;

		for (UINT x = 0; x < _Xcount; ++x)
		{
			CuttingPos.X = _CuttingSize.X * x + _XYOffSet.X * x;
			FTransform insertInst = {};
			insertInst.Scale = _CuttingSize;
			insertInst.Location = CuttingPos;
			NewSprite->PushData(NewImage, insertInst);
		}
		CuttingPos.X = 0.f;
	}
}

