#include "PreCompile.h"
#include "EngineFile.h"
#include "EngineDebug.h"

UEngineFile::UEngineFile()
{


}

// �ڽĿ��� �θ� �����ڸ� ��������� ȣ�����ָ� �ȴ�.
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
	// �Ҹ��ڸ� �̿��ؼ� �ڿ������� �ı��ǵ��� ����°� ����.
	Close();
}

void UEngineFile::FileOpen(const char* _Mode)
{
	fopen_s(&File, Path, _Mode);

	// ����ڵ�
	// ������ ���� ���ߴ�.
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

// �ζ����� ������ �������и��ϸ� �ζ����� �ϱ� ����ϴ�.
bool UEngineFile::IsExits()
{
	int Result = _access(Path, 00);

	// 0�̸� �ִ°� 0 �̿��� ���̸� ���� ��
	return 0 == Result;
}



// ���� ���� Ȥ�� �÷��� ��ɵ��� ������ �ѽ��̴�.
// �����Ѵ�.
// ����Ѵ�.
// ������
void UEngineFile::Close()
{
	// ����ڵ�
	if (nullptr != File)
	{
		fclose(File);
		File = nullptr;
	}
}

