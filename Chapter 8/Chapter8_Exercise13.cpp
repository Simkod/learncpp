//Chapter 8 - Exercise 13
//Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters in each string.
//Also find the longest and the shortest string and the lexicographically first and last string.

#include "std_lib_facilities.h"

vector<int> getStringLenghtsIn(vector<string>& strings)
{
    vector<int> lengths;

    for (vector<string>::const_iterator strIt = strings.begin(); strIt != strings.end(); ++strIt)
    {
        size_t stringLenght = (*strIt).size();

        lengths.push_back(stringLenght);
    }

    return lengths;
}

string getLongestStringIn(vector<string>& strings)
{

    string longestString;

    int longest(INT_MIN);
    for (vector<string>::const_iterator strIt = strings.begin(); strIt != strings.end(); ++strIt)
    {
        int stringLenght = (*strIt).size();
        if (stringLenght > longest)
        {
            longest = stringLenght;
            longestString = *strIt;
        }
    }
    return longestString;
}

string getShortestStringIn(vector<string>& strings)
{
    string shortestString; 

    int shortest(INT_MAX);
    for (vector<string>::const_iterator strIt = strings.begin(); strIt != strings.end(); ++strIt)
    {
        int stringLenght = (*strIt).size();
        if (stringLenght < shortest)
        {
            shortest = stringLenght;
            shortestString = *strIt;
        }
    }
    return shortestString;
}

int main()
{
    vector<string> example{"fik","fak","fuk","LastToPrint","fuk","DoNotPrintThat" };

    vector<int> stringLengths = getStringLenghtsIn(example);
    string longestString = getLongestStringIn(example);
    string shortestString = getShortestStringIn(example);


    system("pause");
}