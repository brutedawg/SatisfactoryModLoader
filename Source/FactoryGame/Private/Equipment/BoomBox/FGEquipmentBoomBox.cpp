// This file has been automatically generated by the Unreal Header Implementation tool

#include "Equipment/BoomBox/FGEquipmentBoomBox.h"

AFGEquipmentBoomBox::AFGEquipmentBoomBox() : Super() {
	this->mBoomBoxPlayer = nullptr;
	this->mOnlyVisibleToOwner = false;
}
void AFGEquipmentBoomBox::SetBoomBoxPlayer( AFGBoomBoxPlayer* player){ }
void AFGEquipmentBoomBox::WasEquipped_Implementation(){ }
void AFGEquipmentBoomBox::WasUnEquipped_Implementation(){ }
void AFGEquipmentBoomBox::WasRemovedFromSlot_Implementation(){ }
void AFGEquipmentBoomBox::WasSlottedIn_Implementation( AFGCharacterPlayer* holder){ }
void AFGEquipmentBoomBox::BeginPlay(){ }
void AFGEquipmentBoomBox::EndPlay(const EEndPlayReason::Type EndPlayReason){ }
void AFGEquipmentBoomBox::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGEquipmentBoomBox, mBoomBoxPlayer);
}
bool AFGEquipmentBoomBox::ShouldSaveState() const{ return bool(); }
void AFGEquipmentBoomBox::OnRep_BoomBoxPlayer( AFGBoomBoxPlayer* oldPlayer){ }
void AFGEquipmentBoomBox::ReleaseBoomBoxPlayer(){ }