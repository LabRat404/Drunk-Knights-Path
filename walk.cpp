#include <iostream>
#include "KnightsPath.h"
using namespace std;
//1155144676 Yeung Tang 1155144676@link.cuhk.edu.hk  
int main()
{ 
    char inputx;
    int inputy;
    int ini = 0;
    
    while (1) { //check first input
        int flag = 0;
        cout << "Enter starting position (col row):";
        cin >> inputx >> inputy;
        inputx = (inputx >= 'A'+ KnightsPath::N) ? flag = 1 : inputx - 'A';
        inputy = (inputy >= KnightsPath::N) ? flag = 1 : inputy;
        inputy = (inputy < 0) ? flag = 1 : inputy;
        if (flag == 0)
            break;
        else
            cout << "Invalid move. Try again!\n";
    }
    KnightsPath kp(inputy, inputx);
    kp.print();
    while (1) { //main game loop
        while (1) { //check input after initializing
            int flag = 0;
            cout << "Enter starting position (col row):";
            cin >> inputx >> inputy;
            inputx = inputx - 'A';
            if (kp.isValid(inputy, inputx))
                break;
            else
                cout << "Invalid move. Try again!\n";
        }
        //Input into grid
        kp.move(inputy, inputx);
        //Print it all
        kp.print();
        //Check if continues
        if (!kp.hasMoreMoves())
            break;
    }
    cout << "Finished! No more  moves!\n";
    //Display different text for different condition
    if (kp.getSteps() >= ((KnightsPath::N * KnightsPath::N)/2))
        cout << "Well done!";
    else
        cout << "Still drunk?Walk wiser!";
}

