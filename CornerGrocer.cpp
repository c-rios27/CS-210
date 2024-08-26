// Carolyn M. Rios Borges
// Sunday August 18, 2024
// CS-210: Module 7 Assignment: Project Three
// Prof. Brian Morgan

#include <iostream>
#include "FrequencyTracker.hpp"

using namespace CornerGrocer;

void printMenu();
int getUserChoice();

void printMenu() { 
    
    // Print Corner Grocer's Order History Menu.

    std::cout << "Corner Grocer's Order History Menu " << std::endl;
    std::cout << "1 : Search for specific item (enter item name) frequency " << std::endl;
    std::cout << "2 : Print frequency in which item(s) was(were) purchased " << std::endl;
    std::cout << "3 : Print item(s) purchase frequency histogram " << std::endl;
    std::cout << "4 : Exit program " << std::endl;
    std::cout << std::endl;

}

int getUserChoice() {

    // Get user's choice from menu.

    int userChoice = 0;
    bool userSelectedChoice = true;

    // Loop over menu options.
    do {
    std::cout << "Please select an option from the menu: ";
    std::cin >> userChoice;
    userSelectedChoice = ((userChoice < 1) || (userChoice > 4));

    if(userSelectedChoice) {
        std::cout << "Invalid choice. Please select from valid choices: 1, 2, 3, and 4. " << std::endl;
    }

    } while(userSelectedChoice); 

    return userChoice;
}

int main (int argc, char* argv[]) {

    FrequencyTracker freqMenu;

    // Access primary files.
    freqMenu.openInputFile("CS210_ProjectThree_InputFile.txt");
    freqMenu.saveWordFrequency("frequency.dat");

    int userChoice = 0;

    // Loop over user's choice.
    do {
    printMenu();
    userChoice = getUserChoice();

    if(userChoice == 1) {
        std::cout << "Please enter item name: ";
        std::string userItemName;
        std::cin >> userItemName;
        int userChoiceNew;
        userChoiceNew = freqMenu.countWordFrequency(userItemName);
        std::cout << "Item frequency: " << userChoiceNew << std::endl;
    }

    else if(userChoice == 2) {
        freqMenu.printWordFrequency();
    }

    else if(userChoice == 3) {
        freqMenu.printWordFreqHistogram();
    }

    } while(userChoice != 4);
    

    return 0;

}