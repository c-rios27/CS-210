// Carolyn M. Rios Borges
// Sunday August 18, 2024
// CS-210: Module 7 Assignment: Project Three
// Prof. Brian Morgan

#ifndef _FREQUENCY_TRACKER_HPP_
#define _FREQUENCY_TRACKER_HPP_

#include <string>
#include <map>

namespace CornerGrocer {
    
    class FrequencyTracker {
        public:
            FrequencyTracker();

            int countWordFrequency(std::string item);

            // Print word frequency, eg. Pumpkin 5.
            void printWordFrequency();

            // Print word frequency, eg. Pumpkin *****.
            void printWordFreqHistogram();

            // Create "frequency.dat" file and save word frequency.
            void saveWordFrequency(std::string outputFile);

            // Open "CS210_ProjectThree_InputFile.txt" file.
            void openInputFile(std::string inputFile);
        
        private:
            std::map<std::string, int> _freqMap;
    };

}

#endif