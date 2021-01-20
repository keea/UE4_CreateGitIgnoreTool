// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CreateGitIgnoreToolBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UCreateGitIgnoreToolBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute CreateGitIgnoreTool Function", Keywords = "CreateGitIgnoreTool"), Category = "CreateGitIgnoreToolTesting")
	static float CreateGitIgnoreToolFunction(float Param);

public:
	UFUNCTION(BlueprintCallable, Category = "Tool")
	static void CreateGitIgnoreFile(FString OriginFile, FString IgnoreFile);

	UFUNCTION(BlueprintCallable, Category = "Tool")
	static FString ChangeFilePath(FString Name, FString Path);

	UFUNCTION(BlueprintCallable, Category = "Tool")
	static void AddToAssetGitIgnore(FString IgnoreFile);

private:
	static void SaveFile(FString FileContent, uint32 type);
};