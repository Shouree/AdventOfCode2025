#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>

int main() {
    std::ifstream inputFile("./day2/input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(inputFile, line);
    std::istringstream ss(line);
    std::string range;
    uint64_t result = 0;

    while(std::getline(ss, range, ',')) {
        size_t dashPos = range.find('-');
        uint64_t start = std::stoull(range.substr(0, dashPos));
        uint64_t end = std::stoull(range.substr(dashPos + 1));
        
        for(size_t i = start; i <= end; ++i) {
            size_t mid = std::to_string(i).size() / 2;
            std::string first = std::to_string(i).substr(0, mid);
            std::string second = std::to_string(i).substr(mid);
            if(first == second)
                result += i;
        }
    }

    std::cout << "Result: " << result << std::endl;
    
    return 0;
}