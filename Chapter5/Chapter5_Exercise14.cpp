
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

enum DayName
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

class Day
{
public:
    Day();
    Day(DayName name);
    ~Day();

    vector<int> getValues() const 
    {
        return m_values;
    }

    void addValue(int number)
    {
        m_values.push_back(number);
    }
    
    DayName getName() 
    {
        return m_name;
    }

private:
    DayName m_name;
    vector<int> m_values;

};

Day::Day()
{
}

Day::Day(DayName name)
    : m_name(name)
{
}

Day::~Day()
{
}

void initializeAcceptedDayExpressions(multimap<DayName, string>* acceptedDayExpressions)
{
    acceptedDayExpressions->insert(pair<DayName, string>(Monday, "mon"));
    acceptedDayExpressions->insert(pair<DayName, string>(Monday, "monday"));

    acceptedDayExpressions->insert(pair<DayName, string>(Tuesday, "tue"));
    acceptedDayExpressions->insert(pair<DayName, string>(Tuesday, "tuesday"));

    acceptedDayExpressions->insert(pair<DayName, string>(Wednesday, "wed"));
    acceptedDayExpressions->insert(pair<DayName, string>(Wednesday, "wednesday"));

    acceptedDayExpressions->insert(pair<DayName, string>(Thursday, "thu"));
    acceptedDayExpressions->insert(pair<DayName, string>(Thursday, "thursday"));

    acceptedDayExpressions->insert(pair<DayName, string>(Friday, "fri"));
    acceptedDayExpressions->insert(pair<DayName, string>(Friday, "friday"));

    acceptedDayExpressions->insert(pair<DayName, string>(Saturday, "sat"));
    acceptedDayExpressions->insert(pair<DayName, string>(Saturday, "saturday"));

    acceptedDayExpressions->insert(pair<DayName, string>(Sunday, "sun"));
    acceptedDayExpressions->insert(pair<DayName, string>(Sunday, "sunday"));
}

bool dayAlreadyAdded(vector<Day>* checkVector, DayName dayName) 
{
    if (checkVector->empty())
    {
        return false;
    }

    for (vector<Day>::const_iterator vectIt = checkVector->begin(); vectIt != checkVector->end(); ++vectIt)
    {
        Day day = *vectIt;
        if (day.getName() == dayName)
        {
            return true;
        }
    }
    return false;
}

Day* findDayfromName(DayName name, vector<Day>* searchVector)
{
    for (vector<Day>::iterator vectIt = searchVector->begin(); vectIt != searchVector->end(); ++vectIt)
    {
        Day day = *vectIt;
        if (day.getName() == name)
        {
            return &(*vectIt);
        }
    }
    return NULL;
}

bool isDayInputAccepted(string inputDay, multimap<DayName, string>* acceptedExpressions)
{
    for (multimap<DayName, string>::const_iterator it = acceptedExpressions->begin(); it != acceptedExpressions->end(); it++)
    {
        if (it->second == inputDay)
        {
            return true;
        }
    }
    return false;
}

DayName getDayNameForInput(string inputDay, multimap<DayName, string>* acceptedExpressions)
{
    DayName outputName;

    for (multimap<DayName, string>::const_iterator it = acceptedExpressions->begin(); it != acceptedExpressions->end(); it++)
    {
        if (it->second == inputDay)
        {
            outputName = it->first;
            return outputName;
        }
    }
}

string dayNameToString(DayName dayName)
{
    string nameAsString;

    switch (dayName)
    {
    case Monday: nameAsString = "Monday"; break;
    case Tuesday: nameAsString = "Tuesday"; break;
    case Wednesday: nameAsString = "Wednesday"; break;
    case Thursday: nameAsString = "Thursday"; break;
    case Friday: nameAsString = "Friday"; break;
    case Saturday: nameAsString = "Saturday"; break;
    case Sunday: nameAsString = "Sunday"; break;
    default: nameAsString = dayName; break;
    }
    return nameAsString;
}

void printSumOfDayValues(vector<Day>* daysVector)
{
    cout << endl;
    for (vector<Day>::const_iterator vectIt = daysVector->begin(); vectIt != daysVector->end(); ++vectIt)
    {
        Day day = *vectIt;

        vector<int> values = day.getValues();
        int valuesSum = accumulate(values.begin(), values.end(), 0);

        string dayName = dayNameToString(day.getName());

        cout << dayName << ":\t\t" << valuesSum;
        cout << endl;
    }
    cout << endl;
}

void printInvalidDayInputs(int invalidInputsNumber)
{
    cout << "Number of invalid day inputs: " << invalidInputsNumber << endl;
    cout << endl;
}

int main()
{
    multimap<DayName, string>* acceptedDayExpressions = new multimap<DayName, string>;
    initializeAcceptedDayExpressions(acceptedDayExpressions);

    vector<Day>* days = new vector<Day>;
    int invalidDayInputcounter(0);

    //get inputs from user
    while (true)
    {
        bool quitExecution(false);
        DayName dayName;
        bool dayInputValid(false);
        while (!dayInputValid)
        {
            cout << "Add a day. If you don't want to add more, type 'DONE': ";
            cin.clear();
            string day;
            cin >> day;
            cout << endl;

            if (day == "DONE")
            {
                quitExecution = true;
                break;
            }

            transform(day.begin(), day.end(), day.begin(), ::tolower);

            if (cin.fail() || !isDayInputAccepted(day, acceptedDayExpressions))
            {
                cout << "Problem with day input. Try again." << endl;
                dayInputValid = false;
                ++invalidDayInputcounter;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
 
            else if (isDayInputAccepted(day, acceptedDayExpressions))
            {
                dayName = getDayNameForInput(day, acceptedDayExpressions);
                dayInputValid = true;
                break;
            }
        }
 
        if (quitExecution) break;

        //Value input
        int value;
        bool valueInputValid(false);
        while (!valueInputValid)
        {
            cout << "Add a value to the day: ";
            cin.clear();
            cin >> value;
            cout << endl;

            if (cin.fail())
            {
                cout << "Problem with value input. Try again." << endl;
                valueInputValid = false;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else
            {
                valueInputValid = true;
                break;
            }
        }
        
        if (dayInputValid && valueInputValid)
        {
            //check if day is already in days vector
            if (!dayAlreadyAdded(days, dayName))
            {
                Day newDay(dayName);
                days->push_back(newDay);
            }
            findDayfromName(dayName, days)->addValue(value);
        }
        else
        {
            cout << "Input Problem.";
        }

    }

    //Output
    printSumOfDayValues(days);
    printInvalidDayInputs(invalidDayInputcounter);

    system("pause");
}