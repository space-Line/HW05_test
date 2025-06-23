// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <cstdlib>

// Sets default values
AMyActor::AMyActor() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    Start = FVector(0, 0, 0);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() {
    Super::BeginPlay();
    Move();
}

int AMyActor::Step() {
    return FMath::RandRange(0, 1); // 0 또는 1 랜덤 반환
}

void AMyActor::Move() {
    int event = 0;
    float distance = 0;
    for (int i = 0; i < 10; i++) {
        int dx = Step();
        int dy = Step();

        // 이동 거리 제한 확인 (둘 다 2 이상 이동 불가)
        if (dx >= 2 || dy >= 2) continue;

        if (rand() % 2 == 0) {
            event++;
            UE_LOG(LogTemp, Warning, TEXT("Event!"));
        }

        Start.X += dx;
        Start.Y += dy;
        
        distance = FVector::Dist(FVector(0, 0, 0), Start);
        UE_LOG(LogTemp, Warning, TEXT("Distance : %f"), distance);

        UE_LOG(LogTemp, Log, TEXT("Step Position = (%f, %f)"), Start.X, Start.Y);
    }
    UE_LOG(LogTemp, Warning, TEXT("Event Count : %d"), event);
}