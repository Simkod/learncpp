//Solve quadratic equations

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout<< "Enter names and scores I will check if it is unique. Terminate with 'NoName' and '0'" << endl;

    string name = "";
    unsigned int score(INT_MIN);

    vector<string> names;
    vector<unsigned int> scores;

    while (true)
    {
        cout << "Name: ";
        cin >> name;
        cout << "Score: ";
        cin >> score;

        if (name == "NoName" && score == 0)
        {
            break;
        }

        names.push_back(name);
        scores.push_back(score);
    }

    bool terminate(false);

    for (vector<string>::iterator nameIt = names.begin(); nameIt != names.end(); ++nameIt)
    {
        unsigned int nameCounter(0);
        for (vector<string>::iterator vectorIt = names.begin(); vectorIt != names.end(); ++vectorIt)
        {
            if (*nameIt == *vectorIt)
            {
                ++nameCounter;
                if (nameCounter >= 2)
                {
                    cout << "Error: name '" << *nameIt << "' is entered " << nameCounter <<" times." << endl;
                    terminate = true;
                    break;
                }
            }
        }
        if (terminate) break;
    }

    cout << "Names and scores:" << endl;

    for (int i=0; i<names.size(); ++i)
    {
        cout << names.at(i) << "\t" << scores.at(i) << endl;
    }

    system("pause");
}