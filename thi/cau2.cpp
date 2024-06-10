#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

int answer;
void menu()
{

    switch (answer)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    default:
        cout << "Bad choice! Exit program: \n";
        break;
    }
}

// ===================================================================================================================
int main()
{
    bool keepLooping = true;
    while (keepLooping)
    {

        cout << "------CHAO MUNG DEN VOI KHACH SAN------  " << endl;
        cout << " (1)    " << endl;
        cout << " (2)    " << endl;
        cout << " (3)   " << endl;
        cout << " (4)   " << endl;
        cout << " (5)   " << endl;
        cout << " (6)    " << endl;
        cout << " (7) " << endl;
        cout << " (8)  " << endl;
        cout << " (9)    " << endl;
        cin >> answer;
        menu();
        if (answer >= 1 && answer <= 10)
            keepLooping = true;
        else
            keepLooping = false;
    }
    getch();
    return answer;
}















