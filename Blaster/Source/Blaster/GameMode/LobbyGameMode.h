// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LobbyGameMode.generated.h"

/**
 *
 */
UCLASS()
class BLASTER_API ALobbyGameMode : public AGameMode
{
    GENERATED_BODY()
public:
    virtual void PostLogin(APlayerController* NewPlayer) override;

    //next 2 lines are testing, try to add extra time to load the map for join player
    UFUNCTION()
    void ServerTravelToBlasterMap();

}; 

// test lines
    //UFUNCTION(NetMulticast, Reliable)
    //void MulticastTravelToBlasterMap();

    //test line

    //virtual bool CanServerTravel(const FString& URL, bool bAbsolute) override { return true; }


//  };

