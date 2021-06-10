#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //print welcome message to the terminal
    std ::cout << std::endl;
    std ::cout << "\nYou are a secret agent , Breaking into a level " << Difficulty;
    std ::cout << " secure server room ...... \nEnter the correct code to contiue...." << std ::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //Declae 3 Number
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print sum and product to the terminal
    std ::cout << std ::endl;
    std ::cout << "+ There are three numbers in the code" << std ::endl;
    std ::cout << "+ The codes added up-to: " << CodeSum << std ::endl;
    std ::cout << "+ The codes multiply to give: " << CodeProduct << std ::endl
               << std ::endl;
    //store player guess
    int GuessA, GuessB, GuessC;
    std ::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std ::cout << "\n ***** Well done agent !! You have extracted the file, Keep going ******"; // We can use "\n" escape sequence in place of "std :: endl"
        return true;
    }
    else
    {
        std::cout << "\n***** You entered the wrong code agent !! be careful and try again ******";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //create new random sequence based on the time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) // loop game untill all level completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std ::cin.clear();  //clear any errors
        std ::cin.ignore(); //Discards any Buffer

        if (bLevelComplete)
        {
            //increase the level of difficulty
            ++LevelDifficulty;
        }
    }
    std ::cout << "\n ****** Congratulation !! You have extracted all the files  , Well done and see you later ******";
    return 0;
}