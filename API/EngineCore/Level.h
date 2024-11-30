#pragma once
#include "GameMode.h"


// �̷������� 
class CollisionLinkData
{
public:
	union
	{
		struct
		{
			int Left;
			int Right;
		};
		__int64 Key;
	};
};


// ���� :
class ULevel : public UObject
{
public:
	friend class U2DCollision;
	friend class USpriteRenderer;
	friend class UEngineAPICore;
	// constrcuter destructer
	ULevel();
	~ULevel();

	// delete Function
	ULevel(const ULevel& _Other) = delete;
	ULevel(ULevel&& _Other) noexcept = delete;
	ULevel& operator=(ULevel&& _Other) noexcept = delete;

	ULevel& operator=(const ULevel& _Other) = delete;
	// ���� CurLevel ������
	void LevelChangeStart();

	// �� ���� ���ο� ������ �ٲ�ž�.
	void LevelChangeEnd();

	void Tick(float _DeltaTime);
	void Render(float _DeltaTime);
	void Collision(float _DeltaTime);
	void Release(float _DeltaTime);

	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();

		AActor* ActorPtr = dynamic_cast<AActor*>(NewActor);
		// ���� �� ���� �����̾�.
		ActorPtr->World = this;

		BeginPlayList.push_back(ActorPtr);
		// NewActor->BeginPlay();
		// AllActors.push_back(NewActor);
		return NewActor;
	}

	void SetCameraToMainPawn(bool _IsCameraToMainPawn)
	{
		IsCameraToMainPawn = _IsCameraToMainPawn;
	}

	void SetCameraPivot(FVector2D _Pivot)
	{
		CameraPivot = _Pivot;
	}

	void SetCameraPos(FVector2D _Pos)
	{
		CameraPos = _Pos;
	}

	void AddCameraPos(FVector2D _Value)
	{
		CameraPos += _Value;
	}

	FVector2D GetCameraPivot()
	{
		return CameraPivot;
	}

	FVector2D GetCameraPos()
	{
		return CameraPos;
	}

	AActor* GetPawn()
	{
		return MainPawn;
	}

	template<typename ConvertType>
	ConvertType* GetPawn()
	{
		return dynamic_cast<ConvertType*>(MainPawn);
	}

	AActor* GetGameMode()
	{
		return GameMode;
	}

	template<typename ConvertType>
	ConvertType* GetGameMode()
	{
		return dynamic_cast<ConvertType*>(GameMode);
	}


	template<typename LeftEnumType, typename RightEnumType>
	static void CollisionGroupLink(LeftEnumType _Left, RightEnumType _Right)
	{
		CollisionGroupLink(static_cast<int>(_Left), static_cast<int>(_Right));
	}

	static void CollisionGroupLink(int _Left, int _Right)
	{
		CollisionLinkData LinkData;
		LinkData.Left = _Left;
		LinkData.Right = _Right;

		for (size_t i = 0; i < CollisionLink.size(); i++)
		{
			// ���� �������� vector
			if (CollisionLink[i].Key == LinkData.Key)
			{
				return;
			}
		}

		CollisionLink.push_back(LinkData);
	}


protected:

private:
	void ScreenClear();
	void DoubleBuffering();
	void BeginPlayCheck();


	// ���ӷ����� �������� ���� ������ �غ��Ű�� �Լ��ε� �������.
	template<typename GameModeType, typename MainPawnType>
	void CreateGameMode()
	{
		GameMode = new GameModeType();

		// ȭ���� �ٶ���ִ� ī�޶��� �����ϰ� ����ŵ� �˴ϴ�.
		MainPawn = new MainPawnType();

		// ���弼���� �����Ǵ°��� ������ �߿��ϴ�.
		MainPawn->World = this;
		GameMode->World = this;

		BeginPlayList.push_back(GameMode);
		BeginPlayList.push_back(MainPawn);

		//GameMode->BeginPlay();
		//MainPawn->BeginPlay();
		//AllActors.push_back(GameMode);
		//AllActors.push_back(MainPawn);
	}

	// �ƹ��� �Ժη� ȣ������ ���ϰ� �ϱ� ���ؼ� private �̾�� �Ѵ�.
	void PushRenderer(class USpriteRenderer* _Renderer);
	void ChangeRenderOrder(class USpriteRenderer* _Renderer, int _PrevOrder);

	void PushCollision(class U2DCollision* _Collision);

	void PushCheckCollision(class U2DCollision* _Collision);

	void CollisionEventCheck(class U2DCollision* _Left, class U2DCollision* _Right);


	// �밡���� ǥ���
	// �̸��� �������
	// �ɹ������� �̸��� �빮��
	// ��������������
	// dujumsaigury
	// �����ǹ̷� ���ֽø� �˴ϴ�.
	// �Ǿո� 
	class AGameMode* GameMode = nullptr;

	// ���ΰ�
	class AActor* MainPawn = nullptr;

	std::list<AActor*> AllActors;

	std::list<AActor*> BeginPlayList;

	bool IsCameraToMainPawn = true;
	// �Ʒ� ������ 2���� ī�޶�.
	FVector2D CameraPos;
	FVector2D CameraPivot;

	// �������� �Ұ��̴�.
	std::map<int, std::list<class USpriteRenderer*>> Renderers;

	// ����ȣ���� ���ؼ� ���� �ִ� �뵵
	std::map<int, std::list<class U2DCollision*>> Collisions;

	// �̺�Ʈ üũ����� ���ؼ� � �׷��� � �׷�� �浹���� ����� ���� �ڷᱸ��
	static std::vector<CollisionLinkData> CollisionLink;

	// �����Ӹ��� �浹üũ�� �ϴ� �ݸ������� ���� ��� ���� �ڷᱸ�� => �̰� ���ϰ� �ʹ�.
	std::map<int, std::list<class U2DCollision*>> CheckCollisions;
};

