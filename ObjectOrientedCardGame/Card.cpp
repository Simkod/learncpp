#include "Card.h"

Card::Card(Figure symbolname) : 
    symbol(symbolname)
{

}

Card::~Card() {

}

Card::Figure Card::getsymbol() const
{
    return symbol;
}
