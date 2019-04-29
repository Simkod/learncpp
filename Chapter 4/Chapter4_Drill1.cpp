//Chapter 4 - Drill 1,2,3,4,5,6,7,8,9,10,11

#include <iostream>
#include <string>
#include "sstream"
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    //int in1, in2; version with ints
    //double in1, in2; version with doubles

    double number;
    string unit;

    const  char termchar = '|';
    const double epsilon = 1.0/100;

    double biggestNumber;
    double smallestNumber;
    bool firstTime = true;
    double sum = 0;

    //conversion factors
    double mtocm = 100;
    double intocm = 2.54;
    double fttoin = 12;

    vector<double> numbersStoredInCm;

    //Solution 1,2,3,4,5
    /*while (cin >> in1 >> in2)
    {

        if (!cin && in1 == termchar)
        {
            break;
        }
        else
        {

        }

        cout << "Number one: " << in1 << "\n" << "Number two: " << in2 << "\n";

        if (in1 < in2)
        {
            cout << "Number one is smallah than number two.\n";
        }
        else if (in1 > in2)
        {
            cout << "Number one is biggah than number two.\n";
        }
        else if (in1 == in2)
        {
            cout << "Number one and number two are equal.\n";
        }
        else
        {

        }

        if (in1-in2 <=epsilon)
        {
            cout << "The numbers are almost equal.\n";
        }

    }*/
 
    //Solution 6,7,8,9,10,11
    while (cin>> number >> unit)
    {

        if (firstTime)
        {
            biggestNumber = number;
            smallestNumber = number;
            firstTime = false;
        }

        cout << "Entered value and unit: " << number << unit<< "\n";

        if (number < smallestNumber)
        {
            smallestNumber = number;
            cout << "smallest so far \n";
        }
        else if (number > biggestNumber)
        {
            biggestNumber = number;
            cout << "largest so far \n";
        }

        
        if (unit == "cm")
        {
            sum += number;
            numbersStoredInCm.push_back(number);
        }
        else if (unit == "m")
        {
            cout << "That is " << number * mtocm << "cm \n";
            sum += number * mtocm;
            numbersStoredInCm.push_back(number * mtocm);
        }
        else if(unit == "in")
        {
            cout << "That is " << number * intocm << "cm \n";
            sum += number * intocm;
            numbersStoredInCm.push_back(number * intocm);
        }
        else if (unit == "ft")
        {
            cout << "That is " << number * fttoin * intocm << "cm \n";
            sum += number * fttoin * intocm;
            numbersStoredInCm.push_back(number * fttoin *intocm);
        }
        else if (unit == "" || unit == "y" || unit == "yard" || unit == "meter" || unit == "km" || unit == "gallons")
        {
            cout << "unit problems";
        }

        if (!cin && number == termchar)
        {
            break;
        }

    }

    cout << "Smallest value: " << smallestNumber << "\nLargestvalue: " << biggestNumber << "\nSum of values: " << sum << "\n";
    sort(numbersStoredInCm.begin(),numbersStoredInCm.end());
    for (int i = 0; i < numbersStoredInCm.size(); ++i)
    {
        cout << numbersStoredInCm[i] << "\n";
    }
    system("pause");
    return 0;
}
