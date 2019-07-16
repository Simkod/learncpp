//Chapter 8 - Exercise 11
//Write a function that finds the smallest and the largest element of a vector argument
//and also computes the mean and the median.
//Do not use global variables. 
//Either return a struct containing the results or pass them back through reference arguments.
//Which of the two ways of returning several result values do you prefer and why ?

#include "std_lib_facilities.h"
#include <vector>
#include <assert.h>

struct VectorData
{
    int smallest;
    int largest;
    double mean;
    vector<int> median;
};

int getLargestInVector(vector<int>& input)
{
    int largest(INT_MIN);

    for (vector<int>::const_iterator vecIt = input.begin(); vecIt != input.end(); ++vecIt)
    {
        if (*vecIt > largest)
        {
            largest = *vecIt;
        }
    }

    return largest;
}

int getSmallestInVector(vector<int>& input)
{
    int smallest(INT_MAX);

    for (vector<int>::const_iterator vecIt = input.begin(); vecIt != input.end(); ++vecIt)
    {
        if (*vecIt < smallest)
        {
            smallest = *vecIt;
        }
    }

    return smallest;
}

int getSumOfVector(vector<int>& input)
{
    int sum(0);

    for (vector<int>::const_iterator vecIt = input.begin(); vecIt != input.end(); ++vecIt)
    {
        sum += *vecIt;
    }

    return sum;
}

double getMeanOfVector(vector<int>& input)
{
    return (double)getSumOfVector(input) / (double)input.size();
}

vector<int> getMedianOfVector(vector<int>& input)
{
    vector<int> medians;

    if (input.size()%2 == 0) //Even
    {
        int medianIndex = (int)((input.size() / 2))-1;
        int median1 = input[medianIndex];
        medians.push_back(median1);

        int median2 = input[medianIndex + 1];
        medians.push_back(median2);
    }
    else //Odd
    {
        int medianIndex = (int)((input.size() / 2));
        int median = input[medianIndex];
        medians.push_back(median);
    }

    //assert(medians.size() > 2);

    return medians;
}

VectorData getVectorData(vector<int>& input)
{
    //smallest
    //largest
    //mean
    //median
    VectorData data;
    data.smallest = getSmallestInVector(input);
    data.largest = getLargestInVector(input);
    data.mean = getMeanOfVector(input);
    data.median = getMedianOfVector(input);

    return data;
}

void printVectorData(VectorData& data)
{
    cout << "Smallest: " << data.smallest << endl;
    cout << "Largest: " << data.largest << endl;
    cout << "Mean: " << data.mean << endl;

   
    if (data.median.size() == 1)
    {
        cout << "Median: ";
    }
    else
    {
        cout << "Medians: ";
    }

    for (int i = 0; i <= data.median.size()-1; ++i)
    {
        if (i > 0)
        {
            cout << ", ";
        }

        cout << data.median[i];
    }

    cout << endl;
}

int main()
{
    vector<int> prices{ 2,3,4,5,6,7 };

    VectorData data = getVectorData(prices);
    printVectorData(data);

    system("pause");
}