
// Chapter 10 Exercise 1

// Write a program that produces the sum of all the numbers in a file of whitespace - separated integers.

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

std::vector<int> getNumbersFromFile(std::string fileNameToOpen)
{
    std::vector<int> numbersRead;

    std::ifstream fileToRead;
    fileToRead.open(fileNameToOpen);
   
    std::string readline;
    if (fileToRead.is_open())
    {
        while (!fileToRead.eof())
        {
            getline(fileToRead, readline);

            std::string temp;
            for (std::string::iterator chIt = readline.begin(); chIt != readline.end(); ++chIt)
            {
                if (*chIt == ' ' || chIt == readline.end())
                {
                    if (temp.empty() || chIt == readline.end())
                    {
                        temp += *chIt;
                    }

                    int newNumber = stoi(temp);
                    numbersRead.push_back(newNumber);

                    temp.erase();
                    continue;
                }
                else
                {
                    temp += *chIt;
                }
            }
        }
    }
    std::cout << "Points read from " << fileNameToOpen << "\n\n";
    return numbersRead;
}

int sumVectorElements(std::vector<int>& vectors) 
{
    int sumOfElements = 0;
    for (int& num : vectors)
    {
        sumOfElements += num;
    }
    return sumOfElements;
}

void printVectorElements(std::vector<int>& vectors)
{
    for (int& num : vectors)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::string fileNameToOpen = "Ch10_Ex1_fileToRead.txt";
    std::vector<int> numbersFromFile = getNumbersFromFile(fileNameToOpen);

    printVectorElements(numbersFromFile);

    int sumInFile = sumVectorElements(numbersFromFile);

    std::cout << sumInFile << "\n";

    system("pause");
}
