//Finding mode of positive integers

#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    vector<unsigned int> numbers = {1,2,4,4,4,5,12,14,15,15,6,6,6,6,6};
    map<unsigned int,unsigned int> numberFrequencies;
    
    //loop through numbers vector
    for (vector<unsigned int>::iterator vectIt = numbers.begin(); vectIt != numbers.end(); ++vectIt)
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
    }

    //Find biggest frequency in counting map
    unsigned int biggestFrequency(0);

    map<unsigned int, unsigned int>::iterator modeIt;

    for (map<unsigned int, unsigned int>::iterator mapIt = numberFrequencies.begin(); mapIt != numberFrequencies.end(); ++mapIt)
    {
        if (mapIt->second > biggestFrequency)
        {
            biggestFrequency = mapIt->second;
            modeIt = mapIt;
        }
    }
    //print mode
    cout << "Mode: " << modeIt->first<< endl << endl;

    system("pause");
}