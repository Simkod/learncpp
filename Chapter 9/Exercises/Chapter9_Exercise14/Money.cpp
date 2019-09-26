#include "Money.h"
#include <vector>
#include <iostream>


Money::Money(int dollars, long int cents)
	: m_dollarAmount(dollars)
	, m_centAmount(cents)
{
	roundCentAmount();
}

Money::~Money()
{
}

void Money::diplayAmount() const
{
	std::cout << "Thats $" << m_dollarAmount << "." << m_centAmount;
	std::cout << "\n";
}

void Money::setCentAmount(long int newCentAmount)
{
	m_centAmount = newCentAmount;
}

void Money::collectDigits(std::vector<int>& digits, long int number)
{
	if (number > 9) {
		collectDigits(digits, number / 10);
	}
	digits.push_back(number % 10);
}

void Money::roundCentAmount()
{
	std::vector<int> digitsInCents;
	collectDigits(digitsInCents, m_centAmount);
	for (std::vector<int>::iterator digitIt = digitsInCents.end() - 1; digitIt != digitsInCents.begin(); --digitIt)
	{
		if (*digitIt >= 5)
		{
			++*(digitIt - 1);
		}
		digitIt = digitsInCents.erase(digitIt);
	}
	
	long int newCentAmount = digitsInCents[0];
	setCentAmount(newCentAmount);
}