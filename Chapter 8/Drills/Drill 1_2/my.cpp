#include "my.h"
#include "std_lib_facilities.h"

using namespace std;

void print_foo()
{
    cout << foo;
    cout << endl;
}

void print(int i)
{
    cout << i;
    cout << endl;
}

void swap_v(int a, int b)
{
    int temp;
    temp = a,
    a = b;
    b = temp;
}

void print_v(int a, int b)
{
    cout << a << "\t" << b;
    cout << endl;
}


void swap_r(int& a, int& b)
{
    int temp;
    temp = a,
        a = b;
    b = temp;
}

void print_r(int& a, int& b)
{
    cout << a << "\t" << b;
    cout << endl;
}

//void swap_cr(const int& a, const int& b)
//{
//    int temp;
//    temp = a,
//    a = b;
//    b = temp;
//}

void print_cr(const int& a, const int& b)
{
    cout << a << "\t" << b;
    cout << endl;
}