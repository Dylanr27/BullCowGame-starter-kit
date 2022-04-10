// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// int32 Length = HiddenWord.Len();
void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Setup game
    SetupGame();
    Intro();
}
void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver == true)
    {
        ClearScreen();
        SetupGame();
        Intro();
        return;
    }
    // Always show instructions unless victory or game over
    Intro();
    // Check the player guess
    ProcessGuess(Input);
}
void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("kruger");
    Lives = 5;
    Length = HiddenWord.Len();
    bGameOver = false;

    // const TCHAR HW[] = TEXT("kruger");
    // PrintLine(TEXT("Character 1 of the hidden word is: %c"), HW[0]);
}

void UBullCowCartridge::EndGame(bool bGameOver)
{
    ClearScreen();
    if (bGameOver)
    {
        PrintLine(TEXT("Hooray you guessed correctly!"));
        PrintLine(TEXT("You had %i attempts remaining"), --Lives);
    }
    else
    {
        PrintLine(TEXT("GAME OVER!!!!"));
        PrintLine(TEXT("The word was: %s"), *HiddenWord);
    }
    PrintLine(TEXT("Press enter to play again..."));
}
void UBullCowCartridge::Intro()
{
    // welcome plauer
    PrintLine(TEXT("    MOOOO! WELCOME TO BULL COWS!! MOOOO!\n"));
    // Explain the game
    PrintLine(TEXT("You must guess a %i letter isogram,"), Length);
    PrintLine(TEXT("You will only get %i attempts,"), Lives);
    PrintLine(TEXT("Press tab to interact with the terminal,"));
    PrintLine(TEXT("Type your guess and press enter to submit."));
    PrintLine(TEXT("Good luck!\n"));
}
void UBullCowCartridge::ProcessGuess(FString PlayerGuess)
{
    if (HiddenWord == PlayerGuess)
    {
        EndGame(bGameOver = true);
        return;
    }

    // Check if Right Number Of Characters & check if isogram
    if (PlayerGuess.Len() != Length || !IsIsoGram(PlayerGuess))
    {
        PrintLine(TEXT("The word you enter MUST have %i letters\nand it MUST also be an Isogram!"), Length);
        return;
    }

    // inform player their guess was unsuccessful as well as their remaining lives
    PrintLine(TEXT("Nice Try Sucka,"));
    PrintLine(TEXT("You have %i attempts remaining"), --Lives);
    if (Lives == 0)
    {
        EndGame(bGameOver);
    }
}

bool UBullCowCartridge::IsIsoGram(FString Word) const
{
    for (int32 i = 0; i < Word.Len(); i++)
    {
        for (int32 j = 0; j < Word.Len(); j++)
        {
            /* code */
        }
        }
    return true;
}