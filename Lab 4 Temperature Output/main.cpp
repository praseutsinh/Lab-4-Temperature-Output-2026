
/*******************************
Nikolas Praseutsinh
Computer Science Fall 2026
Due: October 27, 2026
Lab 4: Lab 4 Temperature Output
Inputs temperature in Celsius and outputs in graph
*********************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>


int main() {
    int number;
    int num_stars;
    std::ifstream MyFile("Temperature_Report.txt");

    //Prints the header
    for (int i = -30; i <= 120; i += 10) {
        std::cout << std::setw(10) << i;
    }
    std::cout << std::endl;

    while (MyFile >> number) {

        // Calculate number of stars, one star each 3 degrees
        num_stars = std::round(number / 3.0);

        // Checks if number is between -30 and 120
        if (number >= -30 && number <= 120) {

            //Figures out the right amount of padding for numbers less then 0
            if (number < 0) {
                std::cout << std::to_string(number);
                int stars = std::abs(num_stars);

                // Moves stars so they end at 0 and 40 is the perfect spot
                std::cout << std::setw(39 - (stars * 3) - std::to_string(number).length()) << "";

                for (int i = 0; i < stars; i++) {
                    std::cout << std::setw(3) << "*";
                }

                std::cout << "|";
            }
            else if (number > 0) {
                std::cout << std::to_string(number);
                std::cout << std::setw(40 - std::to_string(number).length()) << "|";

                for (int i = 0; i < num_stars; i++) {
                    std::cout << std::setw(3) << "*";
                }
            }
            else {
                // if temp is 0
                std::cout << std::to_string(number);
                std::cout << std::setw(40 - std::to_string(number).length()) << "|";
            }
            std::cout << std::endl;
        }

    }

    MyFile.close();
}