#include "PreCompile.h"
#include "EngineString.h"
#include <EngineBase/EngineDebug.h>

UEngineString::UEngineString()
{
}

UEngineString::~UEngineString()
{
}


std::string UEngineString::ToUpper(std::string_view _string)
{
	std::string Result = _string.data();
	Result.resize(_string.size());

	for (size_t i = 0; i < _string.size(); i++)
	{
		Result[i] = std::toupper(_string[i]);
	}
	
	return Result;
}

std::wstring UEngineString::AnsiToUnicode(std::string_view _Name)
{
	// �����찡 �������ٱ�?
	// �⺻������ ��κ��� �ü���� �������ڵ� �����
	// �����ڵ忡 ���ؼ� �����ȴ�.
	// ��κ� �ü���� 2����Ʈ�� ����ǥ���� �Ѱ�� ���ϴ�.
	// �����ڵ带 �����ϴ°��� => OS

	// ��Ƽ����Ʈ�� ���̵� ����Ʈ�� �ٲ��ִ� Ŭ�����Դϴ�.
	// CP_ACP ���� �����ڵ带 ������� �������ּ���.

	// ��Ƽ����Ʈ 200����Ʈ => 1~2����Ʈ�� ǥ���ϴ� �༮ => ���̵� ����Ʈ�� �ٲ۴ٰ�
	//  400����Ʈ
	// �ٲٷ��� �����Ʈ�� �ʿ������� �˾Ƴ��ִ� �Լ��� �ʿ��ϰڳ׿�?

	//�� �Լ��� 2���� ������ ���մϴ�.
	// std::wstring => std::vector<wchar_t> ;

	// ������ 2���� ������
	// �ޱ����� ���̵����Ʈ �޸𸮿�
	// �� �޸��� ũ�⸦ �־��ָ�
	// ��ȯ�� ũ�Ⱑ �󸶰� �Ǵ��� ������ִ� �Լ��� ����˴ϴ�.
	int Size = MultiByteToWideChar(CP_ACP, 0, _Name.data(), static_cast<int>(_Name.size()), nullptr, 0);

	if (0 == Size)
	{
		MSGASSERT("MultiByteToWideChar ���ڿ� ��ȯ�� �����߽��ϴ�" + std::string(_Name));
		return L"";
	}

	std::wstring Result;
	Result.resize(Size);

	Size = MultiByteToWideChar(CP_ACP, 0, _Name.data(), static_cast<int>(_Name.size()), &Result[0], Size);

	if (0 == Size)
	{
		MSGASSERT("MultiByteToWideChar ���ڿ� ��ȯ�� �����߽��ϴ�" + std::string(_Name));
		return L"";
	}

	return Result;
}


