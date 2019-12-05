#include "SGraphPinCustomAsset.h"
#include "Chapter10Editor.h"
#include "SColorPicker.h"
#include "MyCustomAsset.h"

void SGraphPinCustomAsset::Construct(const FArguments& InArgs,
	UEdGraphPin* InPin) {
	SGraphPin::Construct(SGraphPin::FArguments(), InPin);
}

TSharedRef<SWidget>SGraphPinCustomAsset::GetDefaultValueWidget() {
	return SNew(SColorPicker)
		.OnColorCommitted(this,	&SGraphPinCustomAsset::ColorPicked);
}

void SGraphPinCustomAsset::ColorPicked(FLinearColor	SelectedColor) {
	UMyCustomAsset* NewValue = NewObject<UMyCustomAsset>();
	NewValue->Name = SelectedColor.ToFColor(false).ToHex();
	GraphPinObj->GetSchema()->TrySetDefaultObject(*GraphPinObj,
		NewValue);
}