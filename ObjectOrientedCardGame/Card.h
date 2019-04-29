#pragma once

class Card
{
public:

    enum Figure
    {
        KING,
        QUEEN,
        JACK
    };

    Card(Figure symbolname);
    ~Card();

    Figure getsymbol() const;

private:
    Figure symbol;

};
