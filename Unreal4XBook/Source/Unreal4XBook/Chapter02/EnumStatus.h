#pragma once

#include "ObjectMacros.h"

UENUM()
enum Status {
	Stopped UMETA(DisplayName = "Stopped"),
	Moving UMETA(DisplayName = "Moving"),
	Attacking UMETA(DisplayName = "Attacking"),
};