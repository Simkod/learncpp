#pragma once

class Player {

public:

    Player(int AmountOfMoney);
    ~Player();

    int getmoney() const;
    void setmoney(int change);

private:
    int money;

};
