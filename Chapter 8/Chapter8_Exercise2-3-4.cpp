//Chapter 8 - Exercise 2 & 3
// Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for “labeling” the output and a vector.

//Create a vector of Fibonacci numbers and print them using the function from exercise 2.
//To create the vector, write a function, fibonacci(x, y, v, n), 
//where x and y are ints, v is an empty vector<int>, and n is the number of elements to put into v;
//v[0] will be x and v[1] will be y.
//A Fibonacci number is one that is part of a sequence where each element is the sum of the two previous ones.
//For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . .
//Your fibonacci() function should make such a sequence starting with its x and y arguments.

//Estimation for Exercise 4, for int limit:
//x=3,y=6, n=50  2104226199  

//control value: INT_MAX = 2147483647

#include "std_lib_facilities.h"

void fibonacci(int x, int y, vector<int>& v, int n)
{
    v.resize(n);
    v[0] = x;
    v[1] = y;

    for(vector<int>::iterator vectIt = v.begin()+2; vectIt != v.end(); ++vectIt)
    {
        *vectIt = *(vectIt - 2)+ *(vectIt - 1);
    }

}

void print(vector<int>& toPrint, string label)
{
    cout << label;
    cout << endl;
    cout << endl;

    for(vector<int>::const_iterator vecIt = toPrint.begin(); vecIt != toPrint.end(); ++vecIt)
    {
        cout << *vecIt;
        cout << endl;
    }

    cout << endl;
}

int main()
{
    vector<int> nums;

    fibonacci(3,6, nums, 50);

    print(nums, "Fibonacchiiiesss");

    system("pause");
}