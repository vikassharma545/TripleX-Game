#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void PrintS(string s,int t)
{
    for (char c : s)
    {
        this_thread::sleep_for(chrono::milliseconds(t));
        cout << c << flush;
    }
}

void PrintIntroduction(int Difficulty)
{
    string s1 = "You are a secret agent breaking into a level";
    cout << "\n\n\n->";
    PrintS(s1,30);

    this_thread::sleep_for(chrono::milliseconds(30));
    cout << " [" << Difficulty << "] ";

    string s2 = "secure server room...\n-> Entre the correct code number to continue...\n\n";
    PrintS(s2,30);
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % 4;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << endl;
    PrintS(" [Hint]\n\n",40);
    PrintS("+ There are three number in the code\n",40);
    PrintS("+ The code add up to: ",40);
    cout << CodeSum << endl;
    PrintS("+ The code multiply to give: ",40);
    cout << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    PrintS("\nEntre the code...\n",40);
    cin >> GuessA >> GuessB >> GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        PrintS("\nYOU WIN!\n\n   yeeeee.... \\(^-^)/  ",50);
        return true;
    }
    else
    {
        PrintS("\nYOU LOSE!\n\n    Wtf... [-_-] ",50);
        return false;
    }
}

int main()
{
    cout << "********************************************************************\n";
    cout << "************************ TRIPLE-X GAME *****************************\n";
    cout << "********************************************************************";
    int LevelDifficulty = 1;
    const int MaxDifficulty = 8;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();  // Clear any error
        cin.ignore(); // clear the buffer
        if (bLevelComplete)
        {
            ++LevelDifficulty;
            PrintS("\n\n*** Well done agent! You have extracted a file! Keep going! ***",30);
        }
        else
            PrintS("\n\n*** You entre a wrong code! Try again! ***",30);

        cout << "\n--------------------------------------------------------------------------\n\n";
    }

    cout << "\n\n\n***************************** \\[^-^]/ *********************************";
    cout << "\n***                                                                 ***\n";
    cout << "*** Great work agent!  You got all the files! Now get out of there! ***\n";
    cout << "***                                                                 ***\n";
    cout << "***************************** \\[^-^]/ *********************************\n\n\n\n\n\n\n\n";
    return 0;
}
