#include "my.h"
#include <process.h>

int foo;

int main()
{
    //Drill 1
    /*foo = 7;
    print_foo();
    print(99);*/

    //Drill 2
    int x = 7;
    int y = 9;
    print_r(x,y);
    swap_r(x, y);
    print_r(x, y);
    //swap_v(7, 9); //makes no sense...

     const int cx = 7;
     const int cy = 9;
     //swap_r(cx, cy); //makes no sense, value of const int can not be changed
     //swap_?(7.7, 9.9); //makes no sense...

     double dx = 7.7;
     double dy = 9.9;
     //swap_r(dx, dy);  //swap_v() doesn't do anything, swap_cr() makes no sense, and here swap_r takes int-s not doubles
     //swap_?(7.7, 9.9); //makes no sense...

    system("pause");
}