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
		MSGASSERT("파일 경로 일때만 GetFileName을 호출할수 있습니다." + Path.string());
		return "";
	}

	return Path.filename().string();
}

std::string UEnginePath::GetDirectoryName()
{
	if (false == IsDirectory())
	{
		MSGASSERT("디렉토리 경로 일때만 GetDirectoryName을 호출할수 있습니다." + Path.string());
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
	// C++이 빌드되는곳에서는 모두다 동일하게 돌아간다.
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
	// 이런 경우에는 더미를 만드는게 좋다.

	// Path = L"D:\\Project\\GM2\\API\\App\\AAA.png"
	UEnginePath DummyPath = UEnginePath(Path);

	if (false == DummyPath.IsDirectory())
	{
		MSGASSERT("디렉토리 경로일때만 MoveParentToDirectory 를 호출할수 있습니다");
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



