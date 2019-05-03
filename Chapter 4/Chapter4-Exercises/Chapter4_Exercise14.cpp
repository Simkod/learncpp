//Finding Prime numbers with "Sieve of Eratosthenes"
//Between 1-max

#include <vector>
#include <iostream>

using namespace std;



vector<int> createNumbersInRange(int min, int max)
{
    vector<int> resultVector;
    for (int i = min; i <= max; ++i)
    {
        resultVector.push_back(i);
    }
    return resultVector;
}

int main()
{


    //vector containing our primes 
    vector<int> primesFound;

    int minNumber(1);
    int maxNumber(0);

    cout << "Input Until when do you want to get the primes: ";
    cin >> maxNumber;

    vector<int> searchSpace = createNumbersInRange(minNumber, maxNumber);

    vector<int>::iterator vectIt = searchSpace.begin();

    while(*vectIt < 10)
    {
        if (*vectIt == 1)
        {
            vectIt = searchSpace.erase(vectIt);
            continue;
        }

        //go through searchspace, delete what is divideable with *vectIt
        vector<int>::iterator loopVectIt = searchSpace.begin();
        while (loopVectIt != searchSpace.end())
        {
            if (*loopVectIt == *vectIt)
            {
                ++loopVectIt;
                continue;
            }

            if (*loopVectIt % *vectIt == 0)
            {
                loopVectIt = searchSpace.erase(loopVectIt);
            }
            else
            {
                ++loopVectIt;
            }
        }
        ++vectIt;
    }
    
    //print all primes
    cout << "Prime Numbers in ascending order from " << minNumber << " to " << maxNumber << " :" << endl;
    for (vector<int>::iterator vectIt = searchSpace.begin(); vectIt < searchSpace.end(); ++vectIt)
    {
        cout << *vectIt << endl;
    }
    system("pause");
}