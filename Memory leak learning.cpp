#include <iostream>
#include <ostream>


//pointer learning
//int main() {
//
//    
//    int nummah = 37;
//    int* mypointer = &nummah;
//
//    *mypointer = *mypointer + 63;
//
//    std::cout << mypointer <<std::endl<< *mypointer<< std::endl<< mypointer << std::endl << &mypointer << std::endl;
//   
//    system("pause");
//
//    }

//Memory leak learning
//3 cards: J K Q - computer shuffles these cards
//player guesses the position of the cards
//if player wins: gets 3 times his bet
//if loses: loses bet
//starting cash: 100
//can play until money is gone

#include <time.h>

using namespace std;

int cash = 100;

void play(int xbet) {

    srand(time(NULL));
    char *Cards = new char[3];
    Cards[0] = 'J';
    Cards[1] = 'Q';
    Cards[2] = 'K';

    cout << "Shuffling cards... \n";
    
    for (int i = 0; i < 5; ++i) {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = Cards[x];
        Cards[x] = Cards[y];
        Cards[y] = temp;
    }
    int playerguess;
    cout << "Guess the position of the Queen (1, 2, or 3): ";
    cin >> playerguess;

    //get position of Queen

    if (Cards[playerguess-1] == 'Q') {
        cout << "Bingo! You won! :)"<<endl;
        cash = cash + 3 * xbet;
        cout << "Cash: " << cash << endl;
    }
    else {
        cout << "Nope. You loose. :("<<endl;
        cash = cash - xbet;
        cout << "Cash: " << cash << endl;
    }
    cout << "------------------------------------------";
   // free(Cards);
}

int main() {
    int bet;
    while (cash > 0) {
        cout << "Bet: ";
        cin >> bet;
        if (bet == 0 || bet > cash) {
            cout << "nope...";
            break;
        }
        play(bet);
            
    }
}
