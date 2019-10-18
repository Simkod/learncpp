// Chapter 10 Exercise 2

// Write a program that creates a file of data in the form of the temperature "Reading" type defined in §10.5.
// For testing, fill the file with at least 50 “temperature readings.” 
// Call this program store_temps.cpp and the file it creates raw_temps.txt.

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>

struct Reading
{
    int hour;
    double temperature;
};

size_t getNextHour(size_t lastHour)
{
    if (lastHour == 23)
    {
        return 0;
    }
    else
    {
        return ++lastHour;
    }
}

int getNextTemp(int lastTemp, size_t maxChange, int hour, int maxTemp, int minTemp)
{
    int newTemp = 0;
    bool increase;

    if (hour > 6 && hour < 16)
    {
        increase = true;
    }
    else
    {
        increase = false;
    }

    size_t change = rand() % maxChange;

    if (increase)
    {
        newTemp = lastTemp + change;
        if (newTemp > maxTemp)
        {
            newTemp = maxTemp;
        }
    }
    else
    {
        newTemp = lastTemp - change;
        if (newTemp < minTemp)
        {
            newTemp = minTemp;
        }
    }
    return newTemp;
}

std::vector<Reading> initRandomReadings(size_t numberOfReadings)
{
    std::vector<Reading> readings;
    readings.reserve(numberOfReadings);

    srand((unsigned)time(NULL));

    size_t hour = 0;
    int maxTemperature = 40;
    int minTemperature = -30;
    size_t maxTempChangeInAnHour = 4;
    int temperature = rand() % maxTemperature + minTemperature;

    for (size_t index = 0; index < numberOfReadings; ++index)
    {
        hour = getNextHour(hour);
        temperature = getNextTemp(temperature, maxTempChangeInAnHour, hour, maxTemperature, minTemperature);

        Reading newReading;
        newReading.hour = hour;
        newReading.temperature = temperature;

        readings.push_back(newReading);
    }
    return readings;
}

void saveReadingsToFile(std::vector<Reading>& readingsToSave, std::string fileName)
{
    std::ofstream saveToFile;
    saveToFile.open(fileName);

    saveToFile << "Hour[0-23]:\tTemperature[°C]:\n";
    for (Reading readingIt : readingsToSave)
    {
        saveToFile << readingIt.hour << "\t" << readingIt.temperature << "\n";
    }
    saveToFile.close();

    std::cout << "Readings saved to "<< fileName << "\n\n";
}

int main()
{
    size_t numberOfReadings = 50;
    std::vector<Reading> readings = initRandomReadings(numberOfReadings);

    //Save to file
    std::string fileName = "raw_temps.txt";
    saveReadingsToFile(readings, fileName);

    system("pause");
}
