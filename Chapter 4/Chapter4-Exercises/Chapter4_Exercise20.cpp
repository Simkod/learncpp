//Solve quadratic equations

#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    cout<< "Enter names and I will give you the score" << endl;

    map<string, unsigned int> namesAndScores;

    namesAndScores.insert(make_pair("Albert", 1));
    namesAndScores.insert(make_pair("Bert", 2));
    namesAndScores.insert(make_pair("Cecile", 3));
    namesAndScores.insert(make_pair("Daniel", 4));
    namesAndScores.insert(make_pair("Erdogan", 5));
    namesAndScores.insert(make_pair("Felix", 6));
    namesAndScores.insert(make_pair("Gilbert", 7));
    namesAndScores.insert(make_pair("Hans", 8));
    namesAndScores.insert(make_pair("Iris", 9));

    for (map<string,unsigned int>::iterator mapIt = namesAndScores.begin(); mapIt != namesAndScores.end(); ++mapIt)
    {
        cout << mapIt->first << "\t" << mapIt->second << endl;
    }
    cout << endl;

    string name = "";
    cout << "Enter name: ";
    cin >> name;
    cout << endl;

    if (namesAndScores.find(name) != namesAndScores.end())
    {
        cout << "Score for the selected person: " << namesAndScores.find(name)->second << endl << endl;
    }

    system("pause");
}