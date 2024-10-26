#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int spinReel(int currentIndex, int numSymbols)
{
    int rotations = rand() % numSymbols;
    return (currentIndex + rotations) % numSymbols;
}

void printReels(const char* symbols[], int reel1, int reel2, int reel3)
{
    cout << "Result: [" << symbols[reel1] << "] [" << symbols[reel2] << "] [" << symbols[reel3] << "]\n";
}

bool checkWin(int reel1, int reel2, int reel3)
{
    return (reel1 == reel2 && reel2 == reel3);
}

int main()
{
    const char* symbols[] = { "-", "+", "/", "´*", "&", "#" };
    const int numSymbols = sizeof(symbols) / sizeof(symbols[0]);

    srand(static_cast<unsigned int>(time(0)));

    int reel1Index = 0;
    int reel2Index = 0;
    int reel3Index = 0;

    char choice;
    do
    {
        reel1Index = spinReel(reel1Index, numSymbols);
        reel2Index = spinReel(reel2Index, numSymbols);
        reel3Index = spinReel(reel3Index, numSymbols);

        printReels(symbols, reel1Index, reel2Index, reel3Index);

        if (checkWin(reel1Index, reel2Index, reel3Index))
        {
            cout << "Congratulation, you won!\n";
        }
        else
        {
            cout << "Try again :(\n";
        }

        cout << "Click Enter, to play again, or any other key, to exit.";
        choice = cin.get();
        cin.ignore();

    } while (choice == '\n');

    return 0;
}