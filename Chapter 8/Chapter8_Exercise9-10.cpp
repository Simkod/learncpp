//Chapter 8 - Exercise 7
//Write a function that given two vector<double>s price and weight computes a value(an “index”) that is the sum of
//all price[i]*weight[i].
//Make sure to have weight.size() == price.size().

#include "std_lib_facilities.h"
#include <vector>
#include <assert.h>

int multiplyPricesAndWeights(vector<double>& prices, vector<double>& weights)
{
    assert(prices.size() == weights.size() && "Input vectors not equal in size!");
    
    int index(0);

    for (int i = 0; i != prices.size(); ++i )
    {
        index += prices[i] * weights[i];
    }
    return index;
}

template <typename T>
T maxv(vector<T>& input)
{
    T largest(0);

    for (typename vector<T>::const_iterator vecIt = input.begin(); vecIt != input.end(); ++vecIt)
    {
        if (*vecIt > largest)
        {
            largest = *vecIt;
        }
        else
        {
            continue;
        }
    }

    return largest;
}

int main()
{
    vector<double> prices{ 2,3,4,5 };
    vector<double> weights{ 2,3,4,5 };

    int result = multiplyPricesAndWeights(prices, weights);

    cout << maxv(prices) << endl;
     
    system("pause");
}