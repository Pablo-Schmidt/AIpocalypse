// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
    if (NumberOfPlayers == 2)
    {
        UWorld* World = GetWorld();
        if (World)
        {
            bUseSeamlessTravel = true;
            //next line is testing, try to add extra time to load the map for join player
            FTimerHandle TravelTimer;
            GetWorldTimerManager().SetTimer(TravelTimer, this, &ALobbyGameMode::ServerTravelToBlasterMap, 5.0f, false);
            World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
        }
    }
}

void ALobbyGameMode::ServerTravelToBlasterMap()
{
    //next line is testing, try to add extra time to load the map for join player
    FTimerHandle TravelTimer;
    GetWorldTimerManager().SetTimer(TravelTimer, this, &ALobbyGameMode::ServerTravelToBlasterMap, 5.0f, false);
}


/*  TEST LINES
#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
    UE_LOG(LogTemp, Warning, TEXT("Player Joined: %d"), NumberOfPlayers); //test line
    if (NumberOfPlayers == 1)  // Change this if you want more players before traveling
    {
        UE_LOG(LogTemp, Warning, TEXT("Starting ServerTravel to BlasterMap"));// test line
        MulticastTravelToBlasterMap(); // Ensure all clients get the map update
    }
}

void ALobbyGameMode::MulticastTravelToBlasterMap_Implementation()
{
    UWorld* World = GetWorld();
    if (World)
    {
        bUseSeamlessTravel = true;
        World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
    }
}*/