//Read a sequence of double values into a vector.Think of each value as the distance between two cities along a given route.
//Compute and print the total distance(the sum of all distances).
//Find and print the smallest and greatest distance between two neighboring cities.
//Find and print the mean distance between cities.

#include <vector>
#include <iostream>

using namespace std;

int main()
{

    //filling vector
    vector<double> distances(6);
    for (int i = 0; i < distances.size(); ++i)
    {
        double temp;
        cin >> temp;
        distances[i] = temp;
    }
    
    double sumOfDistances = 0;

    //summing vector elements
    for (int i = 0; i < distances.size(); ++i)
    {
        sumOfDistances += distances[i];
    }

    //print distance
    cout <<"Sum of distances: " <<sumOfDistances<<"\n";

    //find smallest and biggest
    int smallest;
    int biggest;

    for (int i = 0; i < distances.size(); ++i)
    {
        if (i == 0)
        {
            smallest = distances[i];
            biggest = distances[i];
        }
        else
        {
            if (distances[i] < smallest)
            {
                smallest = distances[i];
            }
            else if (distances[i] > biggest)
            {
                biggest = distances[i];
            }
        }
    }
    cout << "Biggest: " << biggest << "\n" << "Smallest: " << smallest << "\n" << "Mean of distances: " << sumOfDistances / distances.size();;

    return 0;
}