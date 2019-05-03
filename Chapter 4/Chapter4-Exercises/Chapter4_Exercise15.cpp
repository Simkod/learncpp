//Finding n Prime numbers
//Between n-Max

#include <vector>
#include <iostream>

using namespace std;

bool checkIfPrime(int number)
{
    for (int i = 2; i < number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //vector containing our primes 
    vector<int> primesFound;

    int n(0);

    cout << "Input n: ";
    cin >> n;

    int minNumber(n);
    int maxNumber(INT_MAX);


    //loop from min until max
    for (int currentNumber = minNumber; currentNumber <= maxNumber; ++currentNumber)
    {
        if (primesFound.size() == n) break;

        if (currentNumber == 1) continue;
        //loop through all primes we already have
        if (checkIfPrime(currentNumber))
        {
            primesFound.push_back(currentNumber);
        }
    }


    //print all primes
    cout << "Prime Numbers in ascending order from " << minNumber << " to " << maxNumber << " :" << endl;
    for (vector<int>::iterator vectIt = primesFound.begin(); vectIt < primesFound.end(); ++vectIt)
    {
        cout << *vectIt << endl;
    }
    system("pause");
}