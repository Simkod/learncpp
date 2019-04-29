//Chapter 4 - Exercise 2
//If we define the median of a sequence as “a number so that exactly as many elements come before it in the sequence as
//come after it, ” fix the program in §4.6.3 so that it always prints out a median.Hint: A median need not be an element ofthe sequence.
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> temps;                      // temperatures
    double temp;
        for (int i = 0; i < 5; ++i)
        {// read into temp
            cin >> temp;
            temps.push_back(temp);         // put temp into vector
        }
    // compute median temperature:
    sort(temps.begin(),temps.end());                                     // sort temperatures
    if (temps.size() % 2 == 0) //even
    {
        cout << "Median temperature: " << (temps[(temps.size() / 2) - 1] + temps[(temps.size() / 2)] )/2 << '\n';
    }
    else //odd
    {
        cout << "Median temperature: " << temps[temps.size() / 2] << '\n';
    }
    system("pause");
}