// Chapter 10 Exercise 3

// Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector
// and then calculates the mean and median temperatures in your data set.
// Call this program temp_stats.cpp.

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>
#include <algorithm>

struct Reading
{
    int hour;
    double temperature;
};

struct less_than_key
{
    inline bool operator() (const Reading& struct1, const Reading& struct2)
    {
        return (struct1.temperature < struct2.temperature);
    }
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

    if (hour > 4 && hour < 17)
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

    srand(rand() ^ time(NULL));

    size_t hour = 0;
    int maxTemperature = 40;
    int minTemperature = -30;
    size_t maxTempChangeInAnHour = 4;
    //int temperature = rand() % maxTemperature + minTemperature;
    int temperature = 20;

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

    for (Reading readingIt : readingsToSave)
    {
        saveToFile << readingIt.hour << "\t" << readingIt.temperature << "\n";
    }
    saveToFile.close();

    std::cout << "Readings saved to "<< fileName << "\n\n";
}

void generateExampleFile(int numberOfReadings, std::string fileName)
{
    std::vector<Reading> readings = initRandomReadings(numberOfReadings);
    saveReadingsToFile(readings, fileName);
}

std::vector<Reading> getReadingsFromFile(std::string fileNameToOpen)
{
    std::ifstream fileToRead;
    fileToRead.open(fileNameToOpen);

    std::vector<Reading> readingsProcessed;

    int hour;
    int temperature;

    while (fileToRead >> hour >> temperature)
    {
        Reading newReading;
        newReading.hour = hour;
        newReading.temperature = temperature;
        readingsProcessed.push_back(newReading);
    }

    return readingsProcessed;
}

void printReadings(std::vector<Reading>& readingsToPrint)
{
    std::cout << "Hour[h]:\tTemperature[°C]: \n";
    for (Reading readingIt : readingsToPrint)
    {
        std::cout << readingIt.hour << "\t" << readingIt.temperature << "\n";
    }
    std::cout << "\n";
}

double calculateMeanOfReadings(std::vector<Reading>& readings)
{
    int sum = 0;
    for (Reading readingIt : readings)
    {
        sum += readingIt.temperature;
    }

    return static_cast<double>(sum) / static_cast<double>(readings.size());
}

double calculateMedianOfReadings(std::vector<Reading>& readings)
{
    sort(readings.begin(), readings.end(), less_than_key());

    if (readings.size() % 2 == 0)
    {
        return (readings[readings.size() / 2 - 1].temperature + readings[readings.size() / 2].temperature) / 2;
    }
    else
    {
        return readings[readings.size() / 2].temperature;
    }
}

int main()
{
    size_t numberOfReadings = 51;
    std::string fileName = "raw_temps.txt";
    generateExampleFile(numberOfReadings, fileName);

    std::vector<Reading> processed_readings = getReadingsFromFile(fileName);

    double meanOfReadings = calculateMeanOfReadings(processed_readings);
    double medianOfReadings = calculateMedianOfReadings(processed_readings);

    std::cout << "Mean of Temperatures in " << fileName << ": " << meanOfReadings << "\n";
    std::cout << "Median of Temperatures in " << fileName << ": " << medianOfReadings << "\n";

    system("pause");
}
