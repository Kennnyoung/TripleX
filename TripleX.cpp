#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int LevelDifficulty){
    std::cout << "You are a secret agent breaking into a level " << LevelDifficulty << " secure server room...";
    std::cout << std::endl;
    std::cout << "You need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int LevelDifficulty){

    PrintIntroduction(LevelDifficulty);

    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum << endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
        cout << "You Win!\n";
        return true;
    }else{
        cout << "You Lose!\n";
        return false;
    }
}



int main(){
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        cin.ignore();

        if (bLevelComplete){
            cout << "Heading into next level!\n";
            LevelDifficulty++;
        }else{
            cout << "Try again!\n";
        }
    }

    cout << "Congrats! You finished all levels!";

    return 0;
}