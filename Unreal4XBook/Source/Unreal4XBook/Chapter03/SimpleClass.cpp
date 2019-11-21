#pragma once

#include "SimpleClass.h"
#include "CoreMinimal.h"


SimpleClass::SimpleClass() {
	UE_LOG(LogTemp, Warning, TEXT("CTOR"));
}


SimpleClass::~SimpleClass() {
	UE_LOG(LogTemp, Warning, TEXT("DECTOR"));
}
