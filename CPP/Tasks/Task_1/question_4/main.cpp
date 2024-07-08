#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int initialPopulation = 162100;  // Initial population
    double growthRate = 0.065;       // Annual growth rate (6.5% as decimal)
    int targetPopulation = 1000000;  // One million

    int currentPopulation = initialPopulation;
    int years = 0;

    // Print the initial population
    cout << "Year 0: " << currentPopulation << endl;

    // Calculate and print population each year until it surpasses one million
    while (currentPopulation <= targetPopulation) {
        years++;
        currentPopulation += static_cast<int>(currentPopulation * growthRate); // Calculate new population
        cout << "Year " << years << ": " << currentPopulation << endl;
    }


     // Calculate the number of years required using logarithms not loobs 
    int numberOfYears = ceil(log10(targetPopulation / initialPopulation) / log10(1 + growthRate));

    // Output the result
    cout << "Population surpasses one million in " << numberOfYears << " years." << endl;

    return 0;
}