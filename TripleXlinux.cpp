#include<iostream>
#include <thread>
#include <chrono>
using namespace std;

void PrintIntroduction(int Difficulty)
{
	string s1="You are a secret agent breaking into a level";
	cout<<"\n\n\n->";
    for(int j=0; j< s1. size( ) ; j ++)
    {
     for(int i=0; i<=10000000 ; i++) ;
          cout<<s1[j];
    }
    cout<<" ["<<Difficulty<<"] ";
    string s2="secure server room...\n-> Entre the correct code to continue...\n";
    for(int j=0; j< s2. size( ) ; j ++)
    {
     for(int i=0; i<=10000000 ; i++) ;
          cout<<s2[j];
    }
   cout<<"  \n\n\n->You are a secret agent breaking into a level ["<<Difficulty<<"]";
   cout<<" secure server room...\n-> Entre the correct code to continue...\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    const int CodeA=rand() % Difficulty + 1; 
    const int CodeB=rand() % 4;
    const int CodeC=rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    cout<<endl;
    cout<<" [Hint]\n\n";
    cout<<"+ There are three number in the code"<<endl;
    cout<<"+ The code add up to: "<<CodeSum<<endl;
    cout<<"+ The code multiply to give: "<<CodeProduct<<endl;

    int GuessA,GuessB,GuessC;
    cout<<"\nEntre the code...\n";
    cin>>GuessA>>GuessB>>GuessC;
    int GuessSum = GuessA + GuessB + GuessC ;
    int GuessProduct = GuessA*GuessB*GuessC;

    if(GuessSum==CodeSum && GuessProduct==CodeProduct)
    {
    	cout<<"\n   ";
    	std::string s="YOU WIN!";
    for(char c: s)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << c << std::flush;
    }
        cout<<"\n\n   yeeeee.... \\(^-^)/  ";
        return true;
    }
    else
    {
    	cout<<"\n   ";
    	std::string s="YOU LOSE!";
    for(char c: s)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << c << std::flush;
    }
        cout<<"\n\n    Wtf... [-_-] ";

        return false;
    }
}
int main()
{
	cout<<"********************************************************************\n";
	cout<<"************************ TRIPLE-X GAME *****************************\n";
	cout<<"********************************************************************";
    int LevelDifficulty = 1;
    const int MaxDifficulty = 8;

    while(LevelDifficulty<=MaxDifficulty)
    {
        bool bLevelComplete=PlayGame(LevelDifficulty);
        cin.clear();//Clear any error
        cin.ignore();//clear the buffer
        if(bLevelComplete)
        {
            ++LevelDifficulty;
            cout<<"\n\n*** Well done agent! You have extracted a file! Keep going! ***";
        }
        else
        cout<<"\n\n*** You entre a wrong code! Try again! ***";

        cout<<"\n--------------------------------------------------------------------------\n\n";
    }

   cout<<"\n\n\n***************************** \\[^-^]/ *********************************";
    cout<<"\n***                                                                 ***\n";
    cout<<"*** Great work agent!  You got all the files! Now get out of there! ***\n";
    cout<<"***                                                                 ***\n";
    cout<<"***************************** \\[^-^]/ *********************************\n\n\n\n\n\n\n\n";
    return 0 ;
}

