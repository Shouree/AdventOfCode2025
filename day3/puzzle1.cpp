#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("./day3/input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    int totalJoltage = 0;
    
    while(std::getline(inputFile, line)) {
        int highestJoltage = 0;

        for(int i = 0; i < line.size(); ++i) {
            int joltageRating = 0;
            if(i + 1 > line.size())
                break;

            int firstJoltage = (line[i] - '0') * 10;

            for(int j = i + 1; j < line.size(); ++j) {
                int secondJoltage = line[j] - '0';
                if(firstJoltage + secondJoltage > joltageRating)
                    joltageRating = firstJoltage + secondJoltage;
            }

            highestJoltage = std::max(highestJoltage, joltageRating);
        }
        totalJoltage += highestJoltage;
    }

    std::cout << "Total Joltage: " << totalJoltage << std::endl;
    return 0;
}