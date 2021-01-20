// Fill out your copyright notice in the Description page of Project Settings.


#include "CreateGitIgnoreToolBPLibrary.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManager.h"
#include "Misc/PackageName.h"
#include "Misc/Paths.h"

UCreateGitIgnoreToolBPLibrary::UCreateGitIgnoreToolBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UCreateGitIgnoreToolBPLibrary::CreateGitIgnoreToolFunction(float Param) 
{
	return -1;
}

void UCreateGitIgnoreToolBPLibrary::CreateGitIgnoreFile(FString OriginFile, FString IgnoreFile) 
{
	FString FileContent = TEXT ("\n"+OriginFile);
    FileContent.Append(TEXT("\n## Ignore Asset \n" + IgnoreFile));
    SaveFile(FileContent, EFileWrite::FILEWRITE_NoReplaceExisting);
}

FString UCreateGitIgnoreToolBPLibrary::ChangeFilePath(FString Name, FString Path) 
{
	FString LongPath = FPackageName::LongPackageNameToFilename(Path, ".uasset");
    FString path = LongPath.Replace(*FPaths::ProjectDir(), TEXT(""));
    path = path.Replace(*FString(".").Append(Name), TEXT(""));
    UE_LOG(LogTemp, Log, TEXT("Path : %s"),*path);
    return path;
}

void UCreateGitIgnoreToolBPLibrary::AddToAssetGitIgnore(FString IgnoreFile) 
{
	FString FileContent = TEXT("\n## Ignore Asset \n" + IgnoreFile); 
    SaveFile(FileContent, EFileWrite::FILEWRITE_Append);
}

void UCreateGitIgnoreToolBPLibrary::SaveFile(FString FileContent, uint32 type) 
{
	FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir() + TEXT("/.gitignore"));
    FFileHelper :: SaveStringToFile (FileContent, * FilePath, FFileHelper :: EEncodingOptions :: AutoDetect, & IFileManager :: Get (), type);
}