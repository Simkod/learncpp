//Write a program that checks if a sentence is correct according to the “English” grammar in §6.4.1.
//Assume that every sentence is terminated by a full stop(.) surrounded by whitespace.
//For example, "birds fly but the fish swim." is a sentence, but "birds fly but the fish swim" (terminating dot missing) and "birds fly but the fish swim." (no space before dot) are not.
//For each sentence entered, the program should simply respond “OK” or “not OK.” 

#include "std_lib_facilities.h"

// vectors of words, appropriately classified:
vector<string> nouns;
vector<string> verbs;
vector<string> conjunctions;

void init()
// initialize word classes
{
    nouns.push_back("birds");
    nouns.push_back("fish");
    nouns.push_back("C++");	

    verbs.push_back("rules");
    verbs.push_back("fly");
    verbs.push_back("swim");

    conjunctions.push_back("and");
    conjunctions.push_back("or");
    conjunctions.push_back("but");
}

bool isNoun(string word)
{
    for (vector<string>::const_iterator vectIt = nouns.begin(); vectIt != nouns.end(); vectIt++)
    {
        if (word == *vectIt)
        {
            return true;
        }
        else
        {
        }
    }
    return false;
}
bool isVerb(string word)
{
    for (vector<string>::const_iterator vectIt = verbs.begin(); vectIt != verbs.end(); vectIt++)
    {
        if (word == *vectIt)
        {
            return true;
        }
        else
        {
            
        }
    }
    return false;
}
bool isConjunction(string word)
{
    for (vector<string>::const_iterator vectIt = conjunctions.begin(); vectIt != conjunctions.end(); vectIt++)
    {
        if (word == *vectIt)
        {
            return true;
        }
        else
        {
        }
    }
    return false;
}
bool isSentence()
{
    string word1;
    cin >> word1;
    if (!isNoun(word1)) return false;

    string word2;
    cin >> word2;
    if (!isVerb(word2)) return false;

    string word3;
    cin >> word3;
    if (word3 == ".") return true;
    if (!isConjunction(word3)) return false;
    return isSentence();
}


int main()
{
    init();

    cout << "enter a sentence of the simplified grammar (terminated by a dot):\n";

    while (cin)
    {
        bool sentence = isSentence();

        if (sentence)
        {
            cout << "OK!";
        }
        else
        {
            cout << "not OK!";
        }
        cout << "Try again: ";
    }


    system("pause");
}