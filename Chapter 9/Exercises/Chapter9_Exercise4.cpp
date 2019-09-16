//Chapter 9 Exercise 4

//Look at the headache - inducing last example of §8.4.
//Indent it properly and explain the meaning of each construct.
//Note that the example doesn’t do anything meaningful; it is pure obfuscation.

// dangerously ugly code
struct X 
{
    X() //Constructor for X
    {
    }

    int m; //member variable of X

    void f(int x)   //member function of X
    {
        struct Y 
        {
            int m;  //member variable of Ý

            int f() //member function of Y
            { 
                return 1; 
            } 
        };

        int m;  //variable in f()
        m = x;  //m equals function argument x
        Y m2;   //Create struct Y m2

        return f(m2.f());   //produces an endless loop, because calls itself as a return (always X.f(1) )
    }

    void g(int m)   //member function of X
    {
        if (m)
        {
            f(m + 2);
        }
        else 
        {
            g(m + 2);   //endless loop, calls itself as return
        }
    }

    void m3()   //member function of X, does nothing
    {
    }
    
    void main() //member function of X, with a misleading name (there should be only one main() in a software)
    {
        X a;    //creates X (is it possible?)
        a.f(2); //starts endless loop
    }
};