//Chess inventor reward

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    //give goals (1.000 Grains, 1.000.000 Grains and 1.000.000.000)
    int goalThousand(1000);
    int goalMillion(1000000);
    int goalBillion(1000000000);

    //create chessboard with grains
    int chessBoardSize(64);
    vector<int> chessBoardWithGrains(chessBoardSize);

    for (int index = 0; index < chessBoardWithGrains.size(); ++index)
    {
        chessBoardWithGrains.at(index) = pow(2, index);
    }

    //Loop
    int grainSum(0);
    int squareForThousand(0);
    int squareForMillion(0);
    int squareForBillion(0);
    bool goalThousandReached(false);
    bool goalMillionReached(false);
    bool goalBillionReached(false);

    for (vector<int>::iterator vectIt = chessBoardWithGrains.begin(); vectIt != chessBoardWithGrains.end(); ++vectIt)
    {
        grainSum += *vectIt;
        int squareIndex = distance(chessBoardWithGrains.begin(), vectIt);

        cout << "Square: " << squareIndex << endl;
        cout << "GrainSum: "<< grainSum << endl;
        
        if (goalThousand <= grainSum && !goalThousandReached)
        {
            squareForThousand = squareIndex;
            goalThousandReached = true;
            cout << endl << "!!!Thousand Reached!!!"<< endl << endl;
        }
        if (goalMillion <= grainSum && !goalMillionReached)
        {
            squareForMillion = squareIndex;
            goalMillionReached = true;
            cout << endl << "!!!Million Reached!!!" << endl << endl;
        }
        if (goalBillion <= grainSum && !goalBillionReached)
        {
            squareForBillion = squareIndex;
            goalBillionReached = true;
            cout << endl << "!!!Billion Reached!!!" << endl << endl;
        }
        cout << endl;
    }

    //Give answers
    cout << "1000: \t\t" << squareForThousand << endl;
    cout << "1000000: \t" << squareForMillion << endl;
    cout << "1000000000: \t" << squareForBillion << endl;
    system("pause");
}




