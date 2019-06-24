// Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Name_Value
{
public:
    Name_Value(string name, int value);
    ~Name_Value();

    string m_name;
    int m_value;

private:

};

Name_Value::Name_Value(string name, int value)
    :m_name(name)
    ,m_value(value)
{
}

Name_Value::~Name_Value()
{
}

int main()
{
    cout << "Enter names and scores I will check if it is unique. Terminate with 'NoName' and '0'" << endl;

    string name = "";
    unsigned int score(INT_MIN);

    vector<Name_Value> nameValueVector;

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

        Name_Value newNameValue(name, score);
        nameValueVector.push_back(newNameValue);

    }

    bool terminate(false);

    if (!nameValueVector.empty())
    {
        for (vector<Name_Value>::const_iterator vectIt = nameValueVector.begin(); vectIt != nameValueVector.end(); ++vectIt)
        {
            unsigned int nameCounter(0);
            for (vector<Name_Value>::const_iterator innerVectIt = nameValueVector.begin(); innerVectIt != nameValueVector.end(); ++innerVectIt)
            {
                if ((*vectIt).m_name == (*innerVectIt).m_name)
                {
                    ++nameCounter;
                    if (nameCounter >= 2)
                    {
                        cout << "Error: name '" << (*vectIt).m_name << "' is entered " << nameCounter << " times." << endl;
                        terminate = true;
                        break;
                    }
                }
            }
            if (terminate) break;
        }
    }

    cout << "Names and scores:" << endl;

    for (vector<Name_Value>::const_iterator vectIt = nameValueVector.begin(); vectIt != nameValueVector.end(); ++vectIt)
    {
        cout << (*vectIt).m_name << "\t" << (*vectIt).m_value << endl;;
    }

    system("pause");
}