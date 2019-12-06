// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase_CH11_HTTP.h"

void AMyGameModeBase_CH11_HTTP::BeginPlay() {
	TSharedRef<IHttpRequest> http = FHttpModule::Get().CreateRequest();
	FHttpRequestCompleteDelegate& delegate = http->OnProcessRequestComplete();
	delegate.BindLambda(
		// Anonymous, inlined code function (aka lambda)
		[](FHttpRequestPtr request, FHttpResponsePtr response, bool
			success) -> void {
		UE_LOG(LogTemp, Warning, TEXT("Http Response: %d, %s"),
			request->GetResponse()->GetResponseCode(),
			*request->GetResponse()->GetContentAsString());
	});

	http->OnRequestProgress().BindLambda(
		[this](FHttpRequestPtr request, int32 sentBytes, int32 receivedBytes)
		-> void {
		int32 contentLen = request->GetResponse()->GetContentLength();
		float percentComplete = 100.f * receivedBytes / contentLen;
		UE_LOG(LogTemp, Warning, TEXT("Progress sent=%d bytes / received = %d / %d bytes[%.0f%%]"), sentBytes, receivedBytes, contentLen, percentComplete);
	});

	http->SetURL(TEXT("http://unrealengine.com"));
	http->ProcessRequest();
}