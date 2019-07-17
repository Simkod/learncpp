//Chapter 8 - Exercise 12
//Improve print_until_s() from §8.5.2.
//Test it
//What makes a good set of test cases? Give reasons
//Then, write a print_until_ss() that prints until it sees a second occurrence of its quit argument.

#include "std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
    for (string s : v) 
    {
        if (s == quit) return;
        cout << s << '\n';
    }
}

void print_until_ss(vector<string> v, string quit)
{
    int quitCount(0);

    for (string s : v)
    {
        if (s == quit)
        {
            ++quitCount;
            if (quitCount >= 2)
            {
                return;
            }
        }
        cout << s << '\n';
    }
}


int main()
{
    vector<string> example{"fik","fak","fuk","LastToPrint","fuk","DoNotPrintThat" };

    string quitstring = "fuk";
    print_until_ss(example, quitstring);

    system("pause");
}