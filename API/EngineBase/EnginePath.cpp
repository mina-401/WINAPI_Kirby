#include "PreCompile.h"
#include "EnginePath.h"
#include "EngineDebug.h"

UEnginePath::UEnginePath()
	: Path(std::filesystem::current_path())
{
}

UEnginePath::UEnginePath(std::string_view _Path)
	: Path(_Path)
{

}

UEnginePath::UEnginePath(std::filesystem::path _Path)
	: Path(_Path)
{

}

UEnginePath::~UEnginePath()
{
}

std::string UEnginePath::GetPathToString()
{
	return Path.string();
}

std::string UEnginePath::GetFileName()
{
	if (true == IsDirectory())
	{
		MSGASSERT("���� ��� �϶��� GetFileName�� ȣ���Ҽ� �ֽ��ϴ�." + Path.string());
		return "";
	}

	return Path.filename().string();
}

std::string UEnginePath::GetDirectoryName()
{
	if (false == IsDirectory())
	{
		MSGASSERT("���丮 ��� �϶��� GetDirectoryName�� ȣ���Ҽ� �ֽ��ϴ�." + Path.string());
		return "";
	}

	return Path.filename().string();
}
std::string UEnginePath::GetExtension()
{
	return Path.extension().string();
}


bool UEnginePath::IsExists()
{
	// C++�� ���Ǵ°������� ��δ� �����ϰ� ���ư���.
	// std::filesystem::create_directory()
	return std::filesystem::exists(Path);
}

bool UEnginePath::IsFile()
{
	return false == IsDirectory();
}

bool UEnginePath::IsDirectory()
{
	return std::filesystem::is_directory(Path);
}

void UEnginePath::MoveParent()
{
	Path = Path.parent_path();
}
void UEnginePath::Append(std::string_view _AppendName)
{
	Path.append(_AppendName);
}
bool UEnginePath::MoveParentToDirectory(std::string_view _Path)
{
	// �̷� ��쿡�� ���̸� ����°� ����.

	// Path = L"D:\\Project\\GM2\\API\\App\\AAA.png"
	UEnginePath DummyPath = UEnginePath(Path);

	if (false == DummyPath.IsDirectory())
	{
		MSGASSERT("���丮 ����϶��� MoveParentToDirectory �� ȣ���Ҽ� �ֽ��ϴ�");
		return false;
	}

	bool Result = false;
	std::filesystem::path CurPath = DummyPath.Path;
	while (CurPath != CurPath.root_path())
	{
		CurPath = DummyPath.Path;
		CurPath.append(_Path);
		if (true == std::filesystem::exists(CurPath))
		{
			Result = true;
			Path = CurPath;
			break;
		}
		DummyPath.MoveParent();
	}


	return Result;

	// Path = DummyPath;
}



