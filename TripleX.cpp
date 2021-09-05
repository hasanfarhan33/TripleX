#include <iostream>
#include <ctime>

void AsciiArt()
{
    std::cout << "\n\n MMMMMMMMMMMMMMMMMMMMM.                             MMMMMMMMMMMMMMMMMMMMM" << std::endl;
    std::cout << "   `MMMMMMMMMMMMMMMMMMMM           M\  /M           MMMMMMMMMMMMMMMMMMMM'" << std::endl;
    std::cout << "     `MMMMMMMMMMMMMMMMMMM          MMMMMM          MMMMMMMMMMMMMMMMMMM'" << std::endl;
    std::cout << "       MMMMMMMMMMMMMMMMMMM-_______MMMMMMMM_______-MMMMMMMMMMMMMMMMMMM" << std::endl;
    std::cout << "        MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
    std::cout << "        MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
    std::cout << "        MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
    std::cout << "       .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM." << std::endl;
    std::cout << "      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
    std::cout << "                    `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'" << std::endl;
    std::cout << "                            `MMMMMMMMMMMMMMMMMM'" << std::endl;
    std::cout << "                                `MMMMMMMMMM'" << std::endl;
    std::cout << "                                   MMMMMM :F_P:" << std::endl;
    std::cout << "                                    MMMM" << std::endl;
    std::cout << "                                     MM" << std::endl;
}

void PrintIntroduction(int Difficulty)
{
    AsciiArt();

    std::cout << "\n\nYou are a secret agent breakingn into a level " << Difficulty << " secure server room\n";
    std::cout << "You need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;
    std::cout << std::endl;

    int GuessA, GuessB, GuessC = 0;
    std::cin >> GuessA >> GuessB >> GuessC;

    std::cout << "You entered: " << GuessA << std::endl;
    std::cout << "You entered: " << GuessB << std::endl;
    std::cout << "You entered: " << GuessC << std::endl;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;
    std::cout << std::endl;

    if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
    {
        std::cout << "** Great you got the code right. Now move on to the next level. **\n";
        return true;
    }
    else
    {
        std::cout << "** Wow, how did you manage to become a secret agent? You are actually a dumbass, that's what you are, not a freaking secret agent. You can't even get past this level. Where is your license to be a dumbass? Try again dumbass, you got the code wrong. **. \n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int const MaxDifficulty = 5;
    int LevelDifficulty = 1;

    while (LevelDifficulty <= MaxDifficulty)
    {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  //Clears all the errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete == true)
        {
            LevelDifficulty++;
        }
    }

    std::cout << "** Congratulations! You have successfully completed the whole game. Now go outside, get a life. ** \n";

    return 0;
}