// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup

#include "std_lib_facilities.h"

class Token{
public:

    Token(char ch)  
        :kind(ch)
        ,value(0) 
    { 
    }

    Token(char ch, double val)   
        :kind(ch)
        ,value(val)
    {
    }

    char kind;        
    double value;   
};

class Token_stream {
public:
    Token_stream();   
    Token get();      
    void putback(Token t);    
private:
    bool full;       
    Token buffer;     
};

Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

void Token_stream::putback(Token t)
{
    if (full)
    {
        error("putback() into a full buffer");
    }
    buffer = t;
    full = true;     
}

Token Token_stream::get()
{
    if (full) 
    {       
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) 
    {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(':
    case '{':
    case ')':
    case '}':
    case '+': 
    case '-': 
    case '*':
    case '/':
    {
        return Token(ch);        // let each character represent itself
    }

    case '.':
    case '0':
    case '1': 
    case '2':
    case '3': 
    case '4':
    case '5':
    case '6': 
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('n', val);  // let 'n' represent "a number"
    }
    default:
        error("Bad token");
    }
}

Token_stream ts;        

double expression();    // declaration so that primary() can call expression()

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
        case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
            {
                error("')' expected");
            }
            return d;
        }
        case '{':    // handle '{' expression '}'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}')
            {
                error("'}' expected");
            }
            return d;
        }
        case 'n':           // we use 'n' to represent a number
        {
            return t.value;  // return the number's value
        }
        case 'x':
        {
            ts.putback(t);
            break;
        }
        default:
        {
            error("primary expected");
        }
    }
}

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
        {
            left *= primary();
            t = ts.get();
            break;
        }
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}


int main()
try
{
    cout << "Welcome to our simple calculator." << endl;
    cout << endl;
    cout << "Available operators: *  /  + -" << endl;
    cout << "You can use parentheses as: '(' ')' and '{''}'."<<endl;
    cout << "Print results: type '=' after expressions." << endl;
    cout << "Exit: type 'x'" << endl;
    cout << endl;
    cout << "Please enter expressions using floating - point numbers." << endl;
    

    double val(0);
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'x') break; // 'x' for quit
        if (t.kind == '=')        // '=' for "print now"
            cout << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
    keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
