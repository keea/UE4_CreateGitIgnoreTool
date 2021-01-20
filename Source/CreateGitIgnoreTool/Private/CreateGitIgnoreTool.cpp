// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreateGitIgnoreTool.h"
#include "LevelEditor.h"
#include "SCreateGitIgnoreWidget.h"
#include "Interfaces/IMainFrameModule.h"

static const FName CreateGitIgnoreWindowTabName("Create GitIgnore");
#define LOCTEXT_NAMESPACE "FCreateGitIgnoreToolModule"

void FCreateGitIgnoreToolModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FLevelEditorModule &LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());

	//메뉴 항목 생성 코드
	MenuExtender->AddMenuBarExtension(
		"Help",
		EExtensionHook::After,
		nullptr,
		FMenuBarExtensionDelegate::CreateRaw(this, &FCreateGitIgnoreToolModule::AddMenu));
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);

	//새 탭 생성 및 레지스트
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(CreateGitIgnoreWindowTabName, FOnSpawnTab::CreateRaw(this, &FCreateGitIgnoreToolModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("CreateGitIgnore", "CreateGitIgnoreWindow"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FCreateGitIgnoreToolModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

TSharedRef<SDockTab> FCreateGitIgnoreToolModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs) 
{
	return SNew(SDockTab)
	.TabRole(ETabRole::NomadTab)
	[
		SNew(SCreateGitIgnoreWidget)
	];
}

void FCreateGitIgnoreToolModule::AddMenu(FMenuBarBuilder &MenuBuilder) 
{
	MenuBuilder.AddMenuEntry(
		LOCTEXT("MenuLocKey", "CreateGitIgnore"),
		LOCTEXT("MenuTooltipKey", "Opens menu for CreateGitIgnore"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FCreateGitIgnoreToolModule::MenuCallback)));
}

void FCreateGitIgnoreToolModule::MenuCallback() 
{
	UE_LOG(LogTemp, Log, TEXT("Action! CreateGitIgnore"));

	TSharedRef<SDockTab> NewTap = FGlobalTabmanager::Get()->InvokeTab(CreateGitIgnoreWindowTabName);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCreateGitIgnoreToolModule, CreateGitIgnoreTool)