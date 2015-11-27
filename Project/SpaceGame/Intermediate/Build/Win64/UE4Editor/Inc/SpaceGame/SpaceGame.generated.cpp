// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "SpaceGame.h"
#include "SpaceGame.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpaceGame() {}
	void ACameraPawn::StaticRegisterNativesACameraPawn()
	{
	}
	IMPLEMENT_CLASS(ACameraPawn, 2851626297);
	void AShip::StaticRegisterNativesAShip()
	{
	}
	IMPLEMENT_CLASS(AShip, 3040245790);
static class UEnum* OwnedBy_StaticEnum()
{
	static class UEnum* Singleton = NULL;
	if (!Singleton)
	{
		extern SPACEGAME_API class UEnum* Z_Construct_UEnum_SpaceGame_OwnedBy();
		extern SPACEGAME_API class UPackage* Z_Construct_UPackage_SpaceGame();
		Singleton = GetStaticEnum(Z_Construct_UEnum_SpaceGame_OwnedBy, Z_Construct_UPackage_SpaceGame(), TEXT("OwnedBy"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_OwnedBy(OwnedBy_StaticEnum, TEXT("/Script/SpaceGame"));
	void AFleet::StaticRegisterNativesAFleet()
	{
		FNativeFunctionRegistrar::RegisterFunction(AFleet::StaticClass(),"OnBeginOverlap",(Native)&AFleet::execOnBeginOverlap);
		FNativeFunctionRegistrar::RegisterFunction(AFleet::StaticClass(),"OnEndOverlap",(Native)&AFleet::execOnEndOverlap);
	}
	IMPLEMENT_CLASS(AFleet, 1862482377);
	void ACombat::StaticRegisterNativesACombat()
	{
	}
	IMPLEMENT_CLASS(ACombat, 3229609665);
	void AStar::StaticRegisterNativesAStar()
	{
		FNativeFunctionRegistrar::RegisterFunction(AStar::StaticClass(),"OnBeginOverlap",(Native)&AStar::execOnBeginOverlap);
		FNativeFunctionRegistrar::RegisterFunction(AStar::StaticClass(),"OnEndOverlap",(Native)&AStar::execOnEndOverlap);
	}
	IMPLEMENT_CLASS(AStar, 3980843356);
	void ALink::StaticRegisterNativesALink()
	{
	}
	IMPLEMENT_CLASS(ALink, 3415673960);
	void ASpaceGameGameMode::StaticRegisterNativesASpaceGameGameMode()
	{
	}
	IMPLEMENT_CLASS(ASpaceGameGameMode, 997237742);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_APawn();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API class UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();

	SPACEGAME_API class UClass* Z_Construct_UClass_ACameraPawn_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_ACameraPawn();
	SPACEGAME_API class UClass* Z_Construct_UClass_AShip_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_AShip();
	SPACEGAME_API class UEnum* Z_Construct_UEnum_SpaceGame_OwnedBy();
	SPACEGAME_API class UFunction* Z_Construct_UFunction_AFleet_OnBeginOverlap();
	SPACEGAME_API class UFunction* Z_Construct_UFunction_AFleet_OnEndOverlap();
	SPACEGAME_API class UClass* Z_Construct_UClass_AFleet_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_AFleet();
	SPACEGAME_API class UClass* Z_Construct_UClass_ACombat_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_ACombat();
	SPACEGAME_API class UFunction* Z_Construct_UFunction_AStar_OnBeginOverlap();
	SPACEGAME_API class UFunction* Z_Construct_UFunction_AStar_OnEndOverlap();
	SPACEGAME_API class UClass* Z_Construct_UClass_AStar_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_AStar();
	SPACEGAME_API class UClass* Z_Construct_UClass_ALink_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_ALink();
	SPACEGAME_API class UClass* Z_Construct_UClass_ASpaceGameGameMode_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_ASpaceGameGameMode();
	SPACEGAME_API class UPackage* Z_Construct_UPackage_SpaceGame();
	UClass* Z_Construct_UClass_ACameraPawn_NoRegister()
	{
		return ACameraPawn::StaticClass();
	}
	UClass* Z_Construct_UClass_ACameraPawn()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage_SpaceGame();
			OuterClass = ACameraPawn::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("CameraPawn.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("CameraPawn.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACameraPawn(Z_Construct_UClass_ACameraPawn, TEXT("ACameraPawn"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACameraPawn);
	UClass* Z_Construct_UClass_AShip_NoRegister()
	{
		return AShip::StaticClass();
	}
	UClass* Z_Construct_UClass_AShip()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_SpaceGame();
			OuterClass = AShip::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_morale = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("morale"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(morale, AShip), 0x0000000000000001);
				UProperty* NewProp_defence = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("defence"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(defence, AShip), 0x0000000000000001);
				UProperty* NewProp_health = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("health"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(health, AShip), 0x0000000000000001);
				UProperty* NewProp_damage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("damage"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(damage, AShip), 0x0000000000000001);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Ship.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
				MetaData->SetValue(NewProp_morale, TEXT("Category"), TEXT("Ship"));
				MetaData->SetValue(NewProp_morale, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
				MetaData->SetValue(NewProp_defence, TEXT("Category"), TEXT("Ship"));
				MetaData->SetValue(NewProp_defence, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
				MetaData->SetValue(NewProp_health, TEXT("Category"), TEXT("Ship"));
				MetaData->SetValue(NewProp_health, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
				MetaData->SetValue(NewProp_damage, TEXT("Category"), TEXT("Ship"));
				MetaData->SetValue(NewProp_damage, TEXT("ModuleRelativePath"), TEXT("Ship.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShip(Z_Construct_UClass_AShip, TEXT("AShip"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShip);
	UEnum* Z_Construct_UEnum_SpaceGame_OwnedBy()
	{
		UPackage* Outer=Z_Construct_UPackage_SpaceGame();
		static UEnum* ReturnEnum = NULL;
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OwnedBy"), RF_Public|RF_Transient|RF_Native) UEnum(FObjectInitializer());
			TArray<TPair<FName, uint8>> EnumNames;
			EnumNames.Add(TPairInitializer<FName, uint8>(FName(TEXT("OwnedBy::Neutral")), 0));
			EnumNames.Add(TPairInitializer<FName, uint8>(FName(TEXT("OwnedBy::Player1")), 1));
			EnumNames.Add(TPairInitializer<FName, uint8>(FName(TEXT("OwnedBy::Player2")), 2));
			EnumNames.Add(TPairInitializer<FName, uint8>(FName(TEXT("OwnedBy::OwnedBy_MAX")), 3));
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
			MetaData->SetValue(ReturnEnum, TEXT("Neutral.DisplayName"), TEXT("Neutral"));
			MetaData->SetValue(ReturnEnum, TEXT("Player1.DisplayName"), TEXT("Player1"));
			MetaData->SetValue(ReturnEnum, TEXT("Player2.DisplayName"), TEXT("Player2"));
			MetaData->SetValue(ReturnEnum, TEXT("ToolTip"), TEXT("\"BlueprintType\" is essential to include"));
#endif
		}
		return ReturnEnum;
	}
	UFunction* Z_Construct_UFunction_AFleet_OnBeginOverlap()
	{
		struct Fleet_eventOnBeginOverlap_Parms
		{
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
		UObject* Outer=Z_Construct_UClass_AFleet();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnBeginOverlap"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00420401, 65535, sizeof(Fleet_eventOnBeginOverlap_Parms));
			UProperty* NewProp_SweepResult = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SweepResult"), RF_Public|RF_Transient|RF_Native) UStructProperty(CPP_PROPERTY_BASE(SweepResult, Fleet_eventOnBeginOverlap_Parms), 0x0000008008000182, Z_Construct_UScriptStruct_FHitResult());
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(bFromSweep, Fleet_eventOnBeginOverlap_Parms, bool);
			UProperty* NewProp_bFromSweep = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("bFromSweep"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bFromSweep, Fleet_eventOnBeginOverlap_Parms), 0x0000000000000080, CPP_BOOL_PROPERTY_BITMASK(bFromSweep, Fleet_eventOnBeginOverlap_Parms), sizeof(bool), true);
			UProperty* NewProp_OtherBodyIndex = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherBodyIndex"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(OtherBodyIndex, Fleet_eventOnBeginOverlap_Parms), 0x0000000000000080);
			UProperty* NewProp_OtherComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherComp"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherComp, Fleet_eventOnBeginOverlap_Parms), 0x0000000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			UProperty* NewProp_OtherActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherActor"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherActor, Fleet_eventOnBeginOverlap_Parms), 0x0000000000000080, Z_Construct_UClass_AActor_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
			MetaData->SetValue(NewProp_OtherComp, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFleet_OnEndOverlap()
	{
		struct Fleet_eventOnEndOverlap_Parms
		{
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
		};
		UObject* Outer=Z_Construct_UClass_AFleet();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnEndOverlap"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00020401, 65535, sizeof(Fleet_eventOnEndOverlap_Parms));
			UProperty* NewProp_OtherBodyIndex = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherBodyIndex"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(OtherBodyIndex, Fleet_eventOnEndOverlap_Parms), 0x0000000000000080);
			UProperty* NewProp_OtherComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherComp"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherComp, Fleet_eventOnEndOverlap_Parms), 0x0000000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			UProperty* NewProp_OtherActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherActor"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherActor, Fleet_eventOnEndOverlap_Parms), 0x0000000000000080, Z_Construct_UClass_AActor_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
			MetaData->SetValue(NewProp_OtherComp, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFleet_NoRegister()
	{
		return AFleet::StaticClass();
	}
	UClass* Z_Construct_UClass_AFleet()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_SpaceGame();
			OuterClass = AFleet::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AFleet_OnBeginOverlap());
				OuterClass->LinkChild(Z_Construct_UFunction_AFleet_OnEndOverlap());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_starDefence = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("starDefence"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(starDefence, AFleet), 0x0000000000020001);
				UProperty* NewProp_totalDefence = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("totalDefence"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(totalDefence, AFleet), 0x0000000000020001);
				UProperty* NewProp_totalHealth = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("totalHealth"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(totalHealth, AFleet), 0x0000000000020001);
				UProperty* NewProp_totalDamage = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("totalDamage"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(totalDamage, AFleet), 0x0000000000020001);
				UProperty* NewProp_totalMorale = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("totalMorale"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(totalMorale, AFleet), 0x0000000000020001);
				UProperty* NewProp_ships = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ships"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(ships, AFleet), 0x0000000000000001);
				UProperty* NewProp_ship = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ship"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(ship, AFleet), 0x0000000000000001, Z_Construct_UClass_AShip_NoRegister());
				UProperty* NewProp_Trigger = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Trigger"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(Trigger, AFleet), 0x00000000000a0009, Z_Construct_UClass_UBoxComponent_NoRegister());
				UProperty* NewProp_mesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("mesh"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(mesh, AFleet), 0x0000000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_ownedBy = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ownedBy"), RF_Public|RF_Transient|RF_Native) UByteProperty(CPP_PROPERTY_BASE(ownedBy, AFleet), 0x0000000000000005, Z_Construct_UEnum_SpaceGame_OwnedBy());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AFleet_OnBeginOverlap()); // 1474114864
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AFleet_OnEndOverlap()); // 1387912959
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Fleet.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_starDefence, TEXT("Category"), TEXT("Fleet"));
				MetaData->SetValue(NewProp_starDefence, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_totalDefence, TEXT("Category"), TEXT("Fleet"));
				MetaData->SetValue(NewProp_totalDefence, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_totalHealth, TEXT("Category"), TEXT("Fleet"));
				MetaData->SetValue(NewProp_totalHealth, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_totalDamage, TEXT("Category"), TEXT("Fleet"));
				MetaData->SetValue(NewProp_totalDamage, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_totalMorale, TEXT("Category"), TEXT("Fleet"));
				MetaData->SetValue(NewProp_totalMorale, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_ships, TEXT("Category"), TEXT("Fleet"));
				MetaData->SetValue(NewProp_ships, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_ship, TEXT("Category"), TEXT("Fleet"));
				MetaData->SetValue(NewProp_ship, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_Trigger, TEXT("Category"), TEXT("Triggers"));
				MetaData->SetValue(NewProp_Trigger, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Trigger, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_Trigger, TEXT("ToolTip"), TEXT("UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)\n               Star::OwnedBy ownedBy;"));
				MetaData->SetValue(NewProp_mesh, TEXT("Category"), TEXT("Fleet"));
				MetaData->SetValue(NewProp_mesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_mesh, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
				MetaData->SetValue(NewProp_ownedBy, TEXT("Category"), TEXT("Enum"));
				MetaData->SetValue(NewProp_ownedBy, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFleet(Z_Construct_UClass_AFleet, TEXT("AFleet"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFleet);
	UClass* Z_Construct_UClass_ACombat_NoRegister()
	{
		return ACombat::StaticClass();
	}
	UClass* Z_Construct_UClass_ACombat()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_SpaceGame();
			OuterClass = ACombat::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_aiFleet = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("aiFleet"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(aiFleet, ACombat), 0x0000000000000001, Z_Construct_UClass_AFleet_NoRegister());
				UProperty* NewProp_playerFleet = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("playerFleet"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(playerFleet, ACombat), 0x0000000000000001, Z_Construct_UClass_AFleet_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Combat.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Combat.h"));
				MetaData->SetValue(NewProp_aiFleet, TEXT("Category"), TEXT("Combat"));
				MetaData->SetValue(NewProp_aiFleet, TEXT("ModuleRelativePath"), TEXT("Combat.h"));
				MetaData->SetValue(NewProp_playerFleet, TEXT("Category"), TEXT("Combat"));
				MetaData->SetValue(NewProp_playerFleet, TEXT("ModuleRelativePath"), TEXT("Combat.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACombat(Z_Construct_UClass_ACombat, TEXT("ACombat"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACombat);
	UFunction* Z_Construct_UFunction_AStar_OnBeginOverlap()
	{
		struct Star_eventOnBeginOverlap_Parms
		{
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
		UObject* Outer=Z_Construct_UClass_AStar();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnBeginOverlap"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00420401, 65535, sizeof(Star_eventOnBeginOverlap_Parms));
			UProperty* NewProp_SweepResult = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SweepResult"), RF_Public|RF_Transient|RF_Native) UStructProperty(CPP_PROPERTY_BASE(SweepResult, Star_eventOnBeginOverlap_Parms), 0x0000008008000182, Z_Construct_UScriptStruct_FHitResult());
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(bFromSweep, Star_eventOnBeginOverlap_Parms, bool);
			UProperty* NewProp_bFromSweep = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("bFromSweep"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bFromSweep, Star_eventOnBeginOverlap_Parms), 0x0000000000000080, CPP_BOOL_PROPERTY_BITMASK(bFromSweep, Star_eventOnBeginOverlap_Parms), sizeof(bool), true);
			UProperty* NewProp_OtherBodyIndex = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherBodyIndex"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(OtherBodyIndex, Star_eventOnBeginOverlap_Parms), 0x0000000000000080);
			UProperty* NewProp_OtherComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherComp"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherComp, Star_eventOnBeginOverlap_Parms), 0x0000000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			UProperty* NewProp_OtherActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherActor"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherActor, Star_eventOnBeginOverlap_Parms), 0x0000000000000080, Z_Construct_UClass_AActor_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Star.h"));
			MetaData->SetValue(NewProp_OtherComp, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AStar_OnEndOverlap()
	{
		struct Star_eventOnEndOverlap_Parms
		{
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
		};
		UObject* Outer=Z_Construct_UClass_AStar();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnEndOverlap"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00020401, 65535, sizeof(Star_eventOnEndOverlap_Parms));
			UProperty* NewProp_OtherBodyIndex = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherBodyIndex"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(OtherBodyIndex, Star_eventOnEndOverlap_Parms), 0x0000000000000080);
			UProperty* NewProp_OtherComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherComp"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherComp, Star_eventOnEndOverlap_Parms), 0x0000000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			UProperty* NewProp_OtherActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherActor"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherActor, Star_eventOnEndOverlap_Parms), 0x0000000000000080, Z_Construct_UClass_AActor_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Star.h"));
			MetaData->SetValue(NewProp_OtherComp, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AStar_NoRegister()
	{
		return AStar::StaticClass();
	}
	UClass* Z_Construct_UClass_AStar()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_SpaceGame();
			OuterClass = AStar::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AStar_OnBeginOverlap());
				OuterClass->LinkChild(Z_Construct_UFunction_AStar_OnEndOverlap());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_mesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("mesh"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(mesh, AStar), 0x0000000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_starDefence = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("starDefence"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(starDefence, AStar), 0x0000000000000001);
				UProperty* NewProp_Trigger = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Trigger"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(Trigger, AStar), 0x00000000000a0009, Z_Construct_UClass_UBoxComponent_NoRegister());
				UProperty* NewProp_ownedBy = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ownedBy"), RF_Public|RF_Transient|RF_Native) UByteProperty(CPP_PROPERTY_BASE(ownedBy, AStar), 0x0000000000000005, Z_Construct_UEnum_SpaceGame_OwnedBy());
				UProperty* NewProp_fleetBP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("fleetBP"), RF_Public|RF_Transient|RF_Native) UClassProperty(CPP_PROPERTY_BASE(fleetBP, AStar), 0x0004000000000001, Z_Construct_UClass_AFleet_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AStar_OnBeginOverlap()); // 1173484778
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AStar_OnEndOverlap()); // 925098088
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Star.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Star.h"));
				MetaData->SetValue(NewProp_mesh, TEXT("Category"), TEXT("Star"));
				MetaData->SetValue(NewProp_mesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_mesh, TEXT("ModuleRelativePath"), TEXT("Star.h"));
				MetaData->SetValue(NewProp_starDefence, TEXT("Category"), TEXT("Star"));
				MetaData->SetValue(NewProp_starDefence, TEXT("ModuleRelativePath"), TEXT("Star.h"));
				MetaData->SetValue(NewProp_Trigger, TEXT("Category"), TEXT("Triggers"));
				MetaData->SetValue(NewProp_Trigger, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Trigger, TEXT("ModuleRelativePath"), TEXT("Star.h"));
				MetaData->SetValue(NewProp_ownedBy, TEXT("Category"), TEXT("Enum"));
				MetaData->SetValue(NewProp_ownedBy, TEXT("ModuleRelativePath"), TEXT("Star.h"));
				MetaData->SetValue(NewProp_fleetBP, TEXT("Category"), TEXT("Star"));
				MetaData->SetValue(NewProp_fleetBP, TEXT("ModuleRelativePath"), TEXT("Star.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStar(Z_Construct_UClass_AStar, TEXT("AStar"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStar);
	UClass* Z_Construct_UClass_ALink_NoRegister()
	{
		return ALink::StaticClass();
	}
	UClass* Z_Construct_UClass_ALink()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_SpaceGame();
			OuterClass = ALink::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_Star2 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Star2"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(Star2, ALink), 0x0000000000000001, Z_Construct_UClass_AStar_NoRegister());
				UProperty* NewProp_Star1 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Star1"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(Star1, ALink), 0x0000000000000001, Z_Construct_UClass_AStar_NoRegister());
				UProperty* NewProp_mesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("mesh"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(mesh, ALink), 0x0000000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Link.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Link.h"));
				MetaData->SetValue(NewProp_Star2, TEXT("Category"), TEXT("Link"));
				MetaData->SetValue(NewProp_Star2, TEXT("ModuleRelativePath"), TEXT("Link.h"));
				MetaData->SetValue(NewProp_Star1, TEXT("Category"), TEXT("Link"));
				MetaData->SetValue(NewProp_Star1, TEXT("ModuleRelativePath"), TEXT("Link.h"));
				MetaData->SetValue(NewProp_mesh, TEXT("Category"), TEXT("Link"));
				MetaData->SetValue(NewProp_mesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_mesh, TEXT("ModuleRelativePath"), TEXT("Link.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALink(Z_Construct_UClass_ALink, TEXT("ALink"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALink);
	UClass* Z_Construct_UClass_ASpaceGameGameMode_NoRegister()
	{
		return ASpaceGameGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ASpaceGameGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameMode();
			Z_Construct_UPackage_SpaceGame();
			OuterClass = ASpaceGameGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x2090028C;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SpaceGameGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("SpaceGameGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpaceGameGameMode(Z_Construct_UClass_ASpaceGameGameMode, TEXT("ASpaceGameGameMode"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpaceGameGameMode);
	UPackage* Z_Construct_UPackage_SpaceGame()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/SpaceGame")), false, false));
			ReturnPackage->PackageFlags |= PKG_CompiledIn | 0x00000000;
			FGuid Guid;
			Guid.A = 0xC833AD96;
			Guid.B = 0x7CADA785;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
