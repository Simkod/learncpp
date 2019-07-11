//Chapter 8 - Exercise 5 & 6


#include "std_lib_facilities.h"
#include <assert.h>

template <typename T>
vector<T> reverseToNew(const vector<T>& toReverse) 
{
    assert(!toReverse.empty() && "Empty Input Vector");

    vector<T> reversedVector;
    reversedVector.resize(toReverse.size());

    for(typename vector<T>::const_iterator vecIt = toReverse.begin(); vecIt != toReverse.end(); ++vecIt)
    {
        int reversedIndex = std::distance(vecIt, toReverse.cend());
        reversedVector[reversedIndex-1] = *vecIt;
    }
    return reversedVector;
}

template <typename T>
void reverse(vector<T>& toReverse)
{
    assert(!toReverse.empty() && "Empty Input Vector");

    vector<T> temp;
    temp.resize(toReverse.size());

    for (typename vector<T>::const_iterator vecIt = toReverse.begin(); vecIt != toReverse.end(); ++vecIt)
    {
        int reversedIndex = std::distance(vecIt, toReverse.cend());
        temp[reversedIndex - 1] = *vecIt;
    }
    toReverse = temp;
}



int main()
{
    //Exercise 5
    const vector<int> constant{0,1,2,3,4};
    vector<int> nonConstant{0,1,2,3,4};

    reverse(nonConstant);
    vector<int> constantReversed = reverseToNew(constant);

    //Exercise 6
    const vector<string> constant2{ "Zero","One","Two","Three","Four" };
    vector<string> nonConstant2{ "Zero","One","Two","Three","Four" };

    reverse(nonConstant2);
    vector<string> constantReversed2 = reverseToNew(constant2);

    system("pause");
}