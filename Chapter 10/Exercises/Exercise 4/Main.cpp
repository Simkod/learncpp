// Chapter 10 Exercise 4

// Modify the store_temps.cpp program from exercise 2 to include a temperature suffix c for Celsius or f for Fahrenheit temperatures.
// Then modify the temp_stats.cpp program to test each temperature, converting the Celsius readings to Fahrenheit before putting them into the vector.

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <iomanip>

enum Unit
{
    Celsius,
    Fahrenheit,
    Unknown
};

struct Reading
{
    int hour;
    double temperature;
    Unit unit;
};

struct CalculatedAttribute
{
    std::string name;
    double value;
    Unit unit;
};

struct less_than_key
{
    inline bool operator() (const Reading& struct1, const Reading& struct2)
    {
        return (struct1.temperature < struct2.temperature);
    }
};

void printReadings(std::vector<Reading>& readingsToPrint)
{
    std::cout << "Hour[h]:\tTemperature:\tUnit: \n";
    for (Reading readingIt : readingsToPrint)
    {
        std::cout << readingIt.hour << "\t" << std::setprecision(4) << readingIt.temperature << "\t";

        if (readingIt.unit == Celsius)
        {
            std::cout << "°C";
        }
        else if (readingIt.unit == Fahrenheit)
        {
            std::cout << "F";
        }
        else
        {
            std::cout << "Unit Unknown";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

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

double getNextTemp(double lastTemp, double maxChange, int hour, int maxTemp, int minTemp)
{
    double newTemp = 0;
    bool increase;

    if (hour > 4 && hour < 17)
    {
        increase = true;
    }
    else
    {
        increase = false;
    }

    double change = (maxChange - 0) * ((double)rand() / (double)RAND_MAX) + 0;

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
    double maxTempChangeInAnHour = 4;
    //int temperature = rand() % maxTemperature + minTemperature;
    double temperature = 20;

    for (size_t index = 0; index < numberOfReadings; ++index)
    {
        hour = getNextHour(hour);
        temperature = getNextTemp(temperature, maxTempChangeInAnHour, hour, maxTemperature, minTemperature);

        Reading newReading;
        newReading.hour = hour;
        newReading.temperature = temperature;
        newReading.unit = Celsius;

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
        saveToFile << readingIt.hour << "\t" << readingIt.temperature << "\t";
        if (readingIt.unit == Celsius)
        {
            saveToFile << "°C";
        }
        else if (readingIt.unit == Fahrenheit)
        {
            saveToFile << "F";
        }
        else
        {
            saveToFile << "Unit Unknown";
        }
        saveToFile << "\n";
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
    double temperature;
    std::string unit;

    while (fileToRead >> hour >> temperature >> unit)
    {
        Reading newReading;
        newReading.hour = hour;
        newReading.temperature = temperature;

        Unit newUnit;
        if (unit == "°C")
        {
            newUnit = Celsius;
        }
        else if (unit == "F")
        {
            newUnit = Fahrenheit;
        }
        else
        {
            newUnit = Unknown;
        }
        newReading.unit = newUnit;
        readingsProcessed.push_back(newReading);
    }

    return readingsProcessed;
}

bool checkAllUnitsTheSame(std::vector<Reading>& readings)
{
    Unit firstUnit = readings[0].unit;
    for (Reading& reading : readings)
    {
        if (reading.unit != firstUnit)
        {
            return false;
        }
    }
    return true;
}

void convertReadingsTo(Unit toUnit, std::vector<Reading>& readings)
{
    for (Reading& readingToConvert : readings)
    {
        if (readingToConvert.unit == toUnit)
        {
            continue;
        }

        if (readingToConvert.unit == Celsius)
        {
            double convertedTemperature = (readingToConvert.temperature * (9.0 / 5.0)) + 32;
            readingToConvert.temperature = convertedTemperature;
            readingToConvert.unit = Fahrenheit;
            continue;
        }
        else if (readingToConvert.unit == Fahrenheit)
        {
            double convertedTemperature = (readingToConvert.temperature - 32) * (5 / 9);
            readingToConvert.temperature = convertedTemperature;
            readingToConvert.unit = Fahrenheit;
            continue;
        }
    }
    return;
}

CalculatedAttribute calculateMeanOfReadings(std::vector<Reading> readings, Unit inUnit)
{
    if (!checkAllUnitsTheSame(readings))
    {
        convertReadingsTo(inUnit, readings);
    }

    int sum = 0;
    for (Reading readingIt : readings)
    {
        sum += readingIt.temperature;
    }

    double mean = static_cast<double>(sum) / static_cast<double>(readings.size());

    CalculatedAttribute meanOfReadings;
    meanOfReadings.name = "Mean";
    meanOfReadings.value = mean;
    meanOfReadings.unit = inUnit;

    return meanOfReadings;
}

CalculatedAttribute calculateMedianOfReadings(std::vector<Reading>& readings, Unit inUnit)
{
    if (!checkAllUnitsTheSame(readings))
    {
        convertReadingsTo(inUnit, readings);
    }

    sort(readings.begin(), readings.end(), less_than_key());

    double median;
    if (readings.size() % 2 == 0)
    {
        median = (readings[readings.size() / 2 - 1].temperature + readings[readings.size() / 2].temperature) / 2;
    }
    else
    {
        median = readings[readings.size() / 2].temperature;
    }

    CalculatedAttribute medianOfReadings;
    medianOfReadings.name = "Median";
    medianOfReadings.value = median;
    medianOfReadings.unit = inUnit;

    return medianOfReadings;
}

void printMeanAndMedian(CalculatedAttribute mean, CalculatedAttribute median, std::string fileName)
{
    std::string meanUnitPrint;
    if (mean.unit == Celsius)
    {
        meanUnitPrint = "°C";
    }
    else if (mean.unit == Fahrenheit)
    {
        meanUnitPrint = "F";
    }
    else
    {
        meanUnitPrint = "Unknown Unit";
    }
    std::cout << "Mean of Temperatures in " << fileName << ": " << mean.value << " " << meanUnitPrint << "\n";

    std::string medianUnitPrint;
    if (median.unit == Celsius)
    {
        medianUnitPrint = "°C";
    }
    else if (median.unit == Fahrenheit)
    {
        medianUnitPrint = "F";
    }
    else
    {
        medianUnitPrint = "Unknown Unit";
    }

    std::cout << "Median of Temperatures in " << fileName << ": " << median.value << " " << medianUnitPrint << "\n";
}

int main()
{
    size_t numberOfReadings = 51;
    Unit unitForAllReadings = Fahrenheit;
    std::string fileName = "raw_temps.txt";
    generateExampleFile(numberOfReadings, fileName);

    std::vector<Reading> processed_readings = getReadingsFromFile(fileName);
    convertReadingsTo(unitForAllReadings, processed_readings);

    CalculatedAttribute meanOfReadings = calculateMeanOfReadings(processed_readings, unitForAllReadings);
    CalculatedAttribute medianOfReadings = calculateMedianOfReadings(processed_readings, unitForAllReadings);

    printMeanAndMedian(meanOfReadings, medianOfReadings, fileName);

    system("pause");
}
