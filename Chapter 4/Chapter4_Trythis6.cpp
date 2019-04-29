#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> dislike = { "Broccoli","Lofasz","Pocs" };

int main() {
    for (string inputstring; cin >> inputstring;) {
        if (inputstring == "|") {
            break;
        }
        else
        {
            for (int i = 0; i<dislike.size();++i)
            {
                if (inputstring == dislike[i]) {
                    cout << "BLEEP\n";
                }
            }
        }
    }
    system("pause");
}

