// Carolyn M. Rios Borges
// Sunday August 18, 2024
// CS-210: Module 7 Assignment: Project Three
// Prof. Brian Morgan

#include <iostream>
#include <fstream>
#include <map>
#include "FrequencyTracker.hpp"

using namespace CornerGrocer;

FrequencyTracker::FrequencyTracker() {

}

int FrequencyTracker::countWordFrequency(std::string item) {
    // Check if item exists in _freqMap.
    // If it exists, return frequency.
    // Else, return 0;
    if(_freqMap.count(item) == 0) {
        return 0;
        }
    
    return _freqMap[item];
}

// Print word frequency, eg. Pumpkin 5.
void FrequencyTracker::printWordFrequency() {
    // Loop over _freqMap.
    for (const auto& it : _freqMap) {
        std::cout << it.first
            << " "
            << it.second
            << std::endl; 
    }

}

// Print word frequency, eg. Pumpkin *****.
void FrequencyTracker::printWordFreqHistogram() {
    // Loop over _freqMap.
    for (const auto& it : _freqMap) {
        std::cout << it.first
            << " ";

        for(int i = 0; i < it.second; i++) {
            std::cout << "*"; 
        }

        std::cout << std::endl;
    }
}

// Output file will be "frequency.dat".
void FrequencyTracker::saveWordFrequency(std::string outputFile) {
    
    std::ofstream out(outputFile);

    // Check to see if "frequency.dat" file was created and can be opened.
    if(!out.is_open()) {
        std::cout << "Could not create or open file " << outputFile << std::endl;
        return;
    }

    // Loop over _freqMap and write contents to "frequency.dat" file.
    for (const auto& it : _freqMap) {
        out << it.first
            << " "
            << it.second
            << std::endl; 
    }

    // Close "frequency.dat" file.
    out.flush();
    out.close();

}

// Input file will be "CS210_ProjectThree_InputFile.txt".
void FrequencyTracker::openInputFile(std::string inputFile) {

    std::ifstream in(inputFile);

    // Check to see if "CS210_ProjectThree_InputFile.txt" file can be open.
    if(!in.is_open()) {
        std::cout << "Could not open file " << inputFile << std::endl;
        return;
    }

    std::string word;
    // Count word frequency in "CS210_ProjectThree_InputFile.txt" file.
    while(in >> word) {
        
        if(_freqMap.count(word) == 0) {
            _freqMap[word] = 1;
        }

        else {
            _freqMap[word]++;
        }
        
    }

    // Close "CS210_ProjectThree_InputFile.txt" file.
    in.close();

}


