// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Runtime/Online/HTTP/Public/HttpManager.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/HttpRetrySystem.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"

using namespace FHttpRetrySystem;

#include "MyGameModeBase_CH11_HTTP.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4XBOOK_API AMyGameModeBase_CH11_HTTP : public AGameModeBase
{
	GENERATED_BODY()

public:
	void BeginPlay();
};
