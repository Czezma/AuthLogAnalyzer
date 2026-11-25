#include "utilities.h"
#include <iostream>
#include <string>
#include <limits>

/* Provides input validation for 
   the menu choice in main. */
int getIntegerInput(std::string prompt) {

    // Holds user input.
    int input;

    while (true) {

        std::cout << prompt;

        // If the input is successful,
        if (std::cin >> input) {

            // Send the input back out.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }

        // Display err.
        std::cout << "Invalid input. Please enter a number.\n";

        // Clear the input buffer.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/* Prints a bar of equal signs
   for formatting purposes. */
void printBar(int width) {

    std::cout << std::string(width, '=') << std::endl;
}

// Centers text within width characters.
void centerText(std::string text, int width) {

    // Width cannot be less than zero.
    if (width < 0) {
        std::cout << "Width cannot be less than 0. Please try again.\n";

        return;
    }

    // Calculate the padding. 
    int padding = (width - static_cast<int>(text.length())) / 2;

    // If the padding goes negative,
    if (padding < 0) {

        padding = 0;
    }

    // Print out the result: print the whitespace "padding" amount of times.
    std::cout << std::string(padding, ' ') << text << std::endl;
}

// Displays the main menu text.
void displayMenu() {

    // Print out menu options.
    std::cout << "1. Analyze Authentication Logs\n";
    std::cout << "2. View Project Information\n";
    std::cout << "3. Exit\n\n";
}

// Displays description of the program.
void sentinelDescription() {

    // Print out Sentinel information.
    std::cout << "SENTINEL analyzes authentication logs to identify suspicious login activity.\n";
    std::cout << "Created and maintained by Aidan Head.\n";
}