#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


class CHAPTER14_API SCustomButton : public SCompoundWidget {
	
	SLATE_BEGIN_ARGS(SCustomButton)
		: _Label(TEXT("Default Value"))
		, _ButtonClicked() {}
	SLATE_ATTRIBUTE(FString, Label)
		SLATE_EVENT(FOnClicked, ButtonClicked)
	
	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

	TAttribute<FString> Label;

	FOnClicked ButtonClicked;
};