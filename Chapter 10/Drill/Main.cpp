
// Chapter 10 Drill 1

// 1. Start a program to work with points, discussed in §10.4.Begin by defining the data type Point that has two coordinatemembers x and y.
// 2. Using the code and discussion in §10.4, prompt the user to input seven(x, y) pairs. 
// As the data is entered, store it in a vector of Points called original_points.
// 3. Print the data in original_points to see what it looks like.
// 4. Open an ofstream and output each point to a file named mydata.txt.
// On Windows, we suggest the.txt suffix to make it easier to look at the data with an ordinary text editor(such as WordPad).
// 5. Close the ofstream and then open an ifstream for mydata.txt.Read the data from mydata.txt and store it in a new vector called processed_points.
// 6. Print the data elements from both vectors.
// 7. Compare the two vectors and print "Something's wrong!" if the number of elements or the values of elements differ.

#include "Point.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void initPointsWithUserInput(std::vector<Point>& containerToFill)
{
    int inputX = 0;
    int inputY = 0;
    std::cout << "Enter " << containerToFill.size() << " Points: \n";

    for (int i = 0; i < containerToFill.size(); ++i)
    {
        std::cout << i + 1 << ". Point: \n";
        std::cout << "X: ";
        std::cin >> inputX;
        std::cout << "Y: ";
        std::cin >> inputY;
        std::cout << "\n";
        Point newPoint(inputX, inputY);
        containerToFill[i] = newPoint;
    }
}

void printPoints(std::vector<Point>& pointsToPrint)
{
    std::cout << "X:\tY: \n";
    for (Point pointIt : pointsToPrint)
    {
        std::cout << pointIt.getX() << "\t" << pointIt.getY() << "\n";
    }
    std::cout << "\n";
}

void savePointsToFile(std::vector<Point>& pointsToSave)
{
    std::ofstream saveToFile;
    saveToFile.open("myFile.txt");

    saveToFile << "X:\tY:\n";
    for (Point pointIt : pointsToSave)
    {
        saveToFile << pointIt.getX() << "\t" << pointIt.getY() << "\n";
    }
    saveToFile.close();

    std::cout << "Points saved to myFile.txt\n\n";
}

std::vector<Point> getPointsFromFile(std::string fileNameToOpen)
{
    std::vector<Point> pointsRead;

    std::ifstream fileToRead;
    fileToRead.open(fileNameToOpen);

    std::string readline;
    if (fileToRead.is_open())
    {
        while (!fileToRead.eof())
        {
            getline(fileToRead, readline);
            if (readline == "X:\tY:")
            {
                continue;
            }

            Point newPoint;

            std::string temp;
            for (char ch : readline)
            {
                if (ch == ' ' || ch == '\t' || ch == readline.back())
                {
                    if (temp.empty() || ch == readline.back())
                    {
                        temp += ch;
                    }

                    int newCoordinate = stoi(temp);

                    if (newPoint.getX() == INT_MIN)
                    {
                        newPoint.setX(newCoordinate);
                        temp.erase();
                        continue;
                    }
                    if (newPoint.getY() == INT_MIN)
                    {
                        newPoint.setY(newCoordinate);
                        pointsRead.push_back(newPoint);
                    }
                }
                else
                {
                    temp += ch;
                }
            }
        }
    }
    std::cout << "Points read from " << fileNameToOpen <<"\n\n";
    return pointsRead;
}

void comparePointCollections(std::vector<Point>& PointCollection1, std::vector<Point>& PointCollection2)
{
    std::cout << "Comparison result of two Point collections:\n";
    bool allGood = true;

    if (PointCollection1.size() != PointCollection2.size())
    {
        std::cout << "Collection Sizes differ, the collections are not identical.\n";
        return;
    }

    for (int index = 0; index < PointCollection1.size(); ++index)
    {
        if (PointCollection1[index] != PointCollection2[index])
        {
            std::cout << "Point " << index << " does not match.\n";
            allGood = false;
        }
    }

    if (allGood)
    {
        std::cout << "The two Pointcollection is identical.\n\n";
    }
}

std::vector<Point> createTestPointCollection()
{
    std::vector<Point> points;

    Point point1(1, 2);
    Point point2(3, 3);
    Point point3(5, 9);

    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);

    return points;
}

int main()
{
    int numberOfPoints = 3;
    std::vector<Point> original_points(numberOfPoints);

    initPointsWithUserInput(original_points);

    printPoints(original_points);

    savePointsToFile(original_points);

    std::vector<Point> processed_points = getPointsFromFile("myFile.txt");
    
    printPoints(processed_points);

    comparePointCollections(original_points, processed_points);

    system("pause");
}
