#pragma once
#include <EngineCore/Actor.h>

class ADanceKirby : public AActor
{
public:
    ADanceKirby();
    ~ADanceKirby();

    // delete Function
    ADanceKirby(const ADanceKirby& _Other) = delete;
    ADanceKirby(ADanceKirby&& _Other) noexcept = delete;
    ADanceKirby& operator=(const ADanceKirby& _Other) = delete;
    ADanceKirby& operator=(ADanceKirby&& _Other) noexcept = delete;

    void BeginPlay() override;
    void Tick(float _DeltaTime) override;


    bool IsEndDance = false;

    //void RunSoundPlay();



    void LevelChangeStart() override;
    void LevelChangeEnd() override;
    void SetColImage(std::string_view _ColImageName);

private:
    class USpriteRenderer* SpriteRenderer = nullptr;
};

