#pragma once

#ifndef MONEY_H
#define MONEY_H

#include <vector>

class Money
{
public:
	Money(int dollars, long int cents);
	~Money();

public:
	void diplayAmount() const;

private:
	void collectDigits(std::vector<int>& digits, long int number);
	void setCentAmount(long int newCentAmount);
	void roundCentAmount();

private:
	int m_dollarAmount;
	long int m_centAmount;
};

#endif // !MONEY_H