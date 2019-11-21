// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MemoryAllocator.h"
#include "SimpleClass.h"

void AMemoryAllocator::BeginPlay() {
	CAllocateExample();
	CPPAllocateExample();
}

void AMemoryAllocator::CAllocateExample()
{
	int * i;
	i = (int*)malloc(sizeof(int));
	// Assign the value 0 into variable i
	*i = 0;
	// Use the variable i, ensuring to
	// use dereferencing operator * during use
	UE_LOG(LogTemp, Warning, TEXT("i contains %d"), *i);
	// RELEASING MEMORY OCCUPIED BY i TO THE SYSTEM
	// When we're done using i, we free the memory
	// allocated for it back to the system.
	free(i);
	// Set the pointer's reference to address 0
	i = 0;
}

void AMemoryAllocator::CPPAllocateExample() {
	// Invokes constructor
	SimpleClass * object = new SimpleClass();
	// Invokes deconstrctor
	delete object;
	// resets object to a null pointer
	object = 0;
}