#include "Player.h"
#include <iostream>

Player::Player(int AmountOfMoney) : 
    money(AmountOfMoney)
{

} 

Player::~Player() 
{

}

int Player::getmoney() const
{
    return money;
}

void Player::setmoney(int change)
{
    money = money + change;
}