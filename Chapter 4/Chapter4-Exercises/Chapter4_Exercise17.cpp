//Finding min, max, mode of strings

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> strings = {"uk", "muk", "fuk", "fuk", "fuk", "Yoyoyoyo"};

    map<string , unsigned int> numberFrequencies;
    string minString(50000, 'X');
    string maxString = "";
    
    //loop through words vector
    for (vector<string>::iterator vectIt = strings.begin(); vectIt != strings.end(); ++vectIt)
    {
        //new? 
        if (numberFrequencies.find(*vectIt) == numberFrequencies.end())
        {
            //yes: fill to map
            numberFrequencies.insert(make_pair(*vectIt, 1));
        }
        else
        {
            //no: find it and +1 to counter
            ++numberFrequencies[*vectIt];
        }

        //find min
        if (numberFrequencies.find(*vectIt)->first.size() < minString.size())
        {
            minString = numberFrequencies.find(*vectIt)->first;
        }

        //find max
        if (numberFrequencies.find(*vectIt)->first.size() > maxString.size())
        {
            maxString = numberFrequencies.find(*vectIt)->first;
        }
    }

    //Find biggest frequency in counting map
    unsigned int biggestFrequency(0);

    map<string, unsigned int>::iterator modeIt;

    for (map<string, unsigned int>::iterator mapIt = numberFrequencies.begin(); mapIt != numberFrequencies.end(); ++mapIt)
    {
        if (mapIt->second > biggestFrequency)
        {
            biggestFrequency = mapIt->second;
            modeIt = mapIt;
        }
    }
    //print 
    cout << "Max String: " << maxString << endl;
    cout << "Min String: " << minString << endl;
    cout << "Mode: " << modeIt->first<< endl << endl;

    system("pause");
}