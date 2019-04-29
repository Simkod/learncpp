// Chapter 4 - Try this example
#include <iostream>

#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	double money = 0;
	char curr = ' ';
	double ytod = 0.0090;
	double etod = 1.16;
	double ptod = 1.29;
	
	cout << "Enter currency of money to change to US Dollars \n( y:Yen | e:Euro | p:Pound )\nCurrency: ";
	cin >> curr;

	cout << "Enter amount of money to change to US Dollars\nAmount: ";
	cin >> money;

	//Solution with if
	//if (curr == 'y')
	//	cout << money << " Yen = " << money * ytod << " US Dollars\n";
	//else if (curr == 'e')
	//	cout << money << " Euro = " << money * etod << " US Dollars\n";
	//else if (curr == 'p')
	//	cout << money << " Pound = " << money * ptod << " US Dollars\n";
	//else if (money <= 0)
	//	cout << "No negative money is possible in this case. If you need to change your debt currency, think again about your finances mate...\n";
	//else
	//	cout << "Currency is not listed, please choose from ( y:Yen | e:Euro | p:Pound ).\n";
	//system("pause");

	//Solution with switch case
	if (money <= 0) cout << "No negative money is possible in this case. If you need to change your debt currency, think again about your finances mate...\n";

	switch(curr){
		case 'y':
			cout << money << " Yen = " << money * ytod << " US Dollars\n";
		break;
		case 'e':
			cout << money << " Euro = " << money * etod << " US Dollars\n";
		break;
		case 'p':
			cout << money << " Pound = " << money * ptod << " US Dollars\n";
		break;
		default:
			cout << "Currency is not listed, please choose from ( y:Yen | e:Euro | p:Pound ).\n";
		break;

		}
	system("pause");
	
}