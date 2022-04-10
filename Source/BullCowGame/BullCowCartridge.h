// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString &Input) override;
	void SetupGame();
	void EndGame(bool bGameOver);
	void Intro();
	void ProcessGuess(FString PlayerGuess);
	bool IsIsoGram(FString Word) const;

	// Your declarations go below!
private:
	FString HiddenWord;
	int32 Length;
	int32 Lives;
	bool bGameOver;
};
