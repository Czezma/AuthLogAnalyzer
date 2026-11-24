#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>


/* Function prototypes. */

// Main menu choice input validation.
int getIntegerInput(std::string prompt);

// Prints a bar of equal signs
// for formatting purposes.
void printBar(int width);

// Centers text within width characters.
void centerText(std::string text, int width);

// Displays the menu in main.
void displayMenu();

// General description of 
// the program.
void sentinelDescription();

#endif