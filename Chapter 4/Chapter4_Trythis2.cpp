//Chapter4-Trythis2
//The character 'b' is char('a' + 1), 'c' is char('a' + 2), etc.Use a loop to write out a table of characters with their
//corresponding integer values :
//a     97
//b     98
//. . .
//z     122
#include <iostream>

using namespace std;

int main() {

	char ourchar = 'a';

	////Solution with while
	//while (ourchar<'{')
	//{
	//	cout << ourchar << "\t" << int(ourchar)<<"\n";
	//	++ourchar;
	//		}
	//system("pause");

	//Solution with for
	for (ourchar; ourchar < '{'; ++ourchar) {
		cout << ourchar << "\t" << int(ourchar) << "\t" << char(ourchar-32) << "\n";
	}
	system("pause");
		
}

