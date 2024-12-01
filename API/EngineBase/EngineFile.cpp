#include "PreCompile.h"
#include "EngineFile.h"
#include "EngineDebug.h"

UEngineFile::UEngineFile()
{


}

UEngineFile::UEngineFile(std::string_view _Path)
	: UEnginePath(_Path)
{

}

UEngineFile::UEngineFile(std::filesystem::path _Path)
	: UEnginePath(_Path)
{

}

UEngineFile::~UEngineFile()
{
	Close();
}

void UEngineFile::FileOpen(const char* _Mode)
{
	fopen_s(&File, Path, _Mode);

	if (nullptr == File)
	{
		// char [] Arr0
		// char [] Arr1
		// Arr0 + Arr1

		MSGASSERT(Path /*+ "���� ���¿� �����߽��ϴ�"*/);
	}
}


void UEngineFile::Write(const void* _Ptr, size_t _Size)
{
	if (0 == _Size)
	{
		MSGASSERT("ũ�Ⱑ 0�� �����͸� ������ �����ϴ�.");
	}

	if (nullptr == _Ptr)
	{
		MSGASSERT("�������� �ʴ� �޸𸮸� ����Ϸ��� �߽��ϴ�.");
	}

	// w�� ��쿡 ���� ����ó��
	if (nullptr == File)
	{
		MSGASSERT("���� ���� ���Ͽ� ������ ������ �߽��ϴ�");
		return;
	}

	fwrite(_Ptr, _Size, 1, File);
}

void UEngineFile::Read(void* _Ptr, size_t _Size)
{
	if (0 == _Size)
	{
		MSGASSERT("ũ�Ⱑ 0�� �����͸� �������� �����ϴ�.");
	}

	if (nullptr == _Ptr)
	{
		MSGASSERT("�������� �ʴ� �޸𸮸� �������� �߽��ϴ�.");
	}

	if (nullptr == File)
	{
		MSGASSERT("���� ���� ���Ͽ� ������ ������ �߽��ϴ�");
		return;
	}

	fread(_Ptr, _Size, 1, File);
}

bool UEngineFile::IsExits()
{
	int Result = _access(Path, 00);

	return 0 == Result;
}




void UEngineFile::Close()
{
	if (nullptr != File)
	{
		fclose(File);
		File = nullptr;
	}
}

