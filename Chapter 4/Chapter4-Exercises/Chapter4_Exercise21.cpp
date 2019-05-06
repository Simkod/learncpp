#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename K, typename V>
bool findByValue(std::vector<K> & vec, std::map<K, V> mapOfElemen, V value)
{
    bool bResult = false;
    auto it = mapOfElemen.begin();
    // Iterate through the map
    while (it != mapOfElemen.end())
    {
        // Check if value of this entry matches with given value
        if (it->second == value)
        {
            // Yes found
            bResult = true;
            // Push the key in given map
            vec.push_back(it->first);
        }
        // Go to next entry in map
        it++;
    }
    return bResult;
}

int main()
{
    cout<< "Enter a score and I will give you the name(s)" << endl;

    map<string, unsigned int> namesAndScores;

    namesAndScores.insert(make_pair("Albert", 1));
    namesAndScores.insert(make_pair("Bert", 2));
    namesAndScores.insert(make_pair("Cecile", 3));
    namesAndScores.insert(make_pair("Daniel", 4));
    namesAndScores.insert(make_pair("Erdogan", 5));
    namesAndScores.insert(make_pair("Felix", 6));
    namesAndScores.insert(make_pair("Gilbert", 7));
    namesAndScores.insert(make_pair("Hans", 5));
    namesAndScores.insert(make_pair("Iris", 9));

    for (map<string,unsigned int>::iterator mapIt = namesAndScores.begin(); mapIt != namesAndScores.end(); ++mapIt)
    {
        cout << mapIt->first << "\t" << mapIt->second << endl;
    }
    cout << endl;

    unsigned int score;
    cout << "Enter score: ";
    cin >> score;
    cout << endl;

    vector<string> resultNames;

    if (findByValue(resultNames, namesAndScores, score))
    {
        cout << "Persons with " << score << " scores: " << endl;
        for (vector<string>::iterator vectIt = resultNames.begin(); vectIt != resultNames.end(); ++vectIt)
        {
            cout << *vectIt << endl;
        }

        cout << endl;
    }

    

    system("pause");
}