#include <iostream>
#include <fstream>
#include <cstdint>

int main() {
    std::ifstream inputFile("./day3/input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    uint64_t totalJoltage = 0;
    
    while(std::getline(inputFile, line)) {
        std::string currJoltage = line.substr(0, 12);

        for(int i = currJoltage.size(); i < line.size(); ++i) {
            uint64_t joltageRating = std::stoull(currJoltage);

            for(int j = 0; j < currJoltage.size(); ++j) {
                std::string candidate = currJoltage;
                candidate.erase(candidate.begin() + j);
                candidate.push_back(line[i]);
                if(candidate > currJoltage) {
                    currJoltage = candidate;
                    break;
                }
            }
        }

        totalJoltage += std::stoull(currJoltage);
    }

    std::cout << "Total Joltage: " << totalJoltage << std::endl;
    return 0;
}