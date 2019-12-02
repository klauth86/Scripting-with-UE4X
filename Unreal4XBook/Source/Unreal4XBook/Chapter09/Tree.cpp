// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"

#include "ConstructorHelpers.h"

ATree::ATree() {
	// Set this actor to call Tick() every frame. You can turn
	// this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset =
		ConstructorHelpers::FObjectFinder<UStaticMesh>
		(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	
	if (UStaticMeshComponent * SM = GetStaticMeshComponent()) {
		if (MeshAsset.Object != nullptr) {
			SM->SetStaticMesh(MeshAsset.Object);
			SM->SetGenerateOverlapEvents(true);
		}
		SM->SetMobility(EComponentMobility::Movable);
	}
}