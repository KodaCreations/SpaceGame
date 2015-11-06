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
	void AFleet::StaticRegisterNativesAFleet()
	{
	}
	IMPLEMENT_CLASS(AFleet, 4108666403);
	void ASpaceGameGameMode::StaticRegisterNativesASpaceGameGameMode()
	{
	}
	IMPLEMENT_CLASS(ASpaceGameGameMode, 997237742);
	void AStar::StaticRegisterNativesAStar()
	{
	}
	IMPLEMENT_CLASS(AStar, 2991637635);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();

	SPACEGAME_API class UClass* Z_Construct_UClass_AFleet_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_AFleet();
	SPACEGAME_API class UClass* Z_Construct_UClass_ASpaceGameGameMode_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_ASpaceGameGameMode();
	SPACEGAME_API class UClass* Z_Construct_UClass_AStar_NoRegister();
	SPACEGAME_API class UClass* Z_Construct_UClass_AStar();
	SPACEGAME_API class UPackage* Z_Construct_UPackage_SpaceGame();
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


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Fleet.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Fleet.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFleet(Z_Construct_UClass_AFleet, TEXT("AFleet"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFleet);
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


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Star.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Star.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStar(Z_Construct_UClass_AStar, TEXT("AStar"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStar);
	UPackage* Z_Construct_UPackage_SpaceGame()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/SpaceGame")), false, false));
			ReturnPackage->PackageFlags |= PKG_CompiledIn | 0x00000000;
			FGuid Guid;
			Guid.A = 0x0628242D;
			Guid.B = 0xFF7C85FD;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
