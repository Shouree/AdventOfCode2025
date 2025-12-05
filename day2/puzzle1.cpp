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
            std::string iStr = std::to_string(i);

            if(iStr.size() % 2 != 0)
                continue;
            
            size_t mid = iStr.size() / 2;
            std::string first = iStr.substr(0, mid);
            std::string second = iStr.substr(mid);

            if(first == second)
                result += i;
        }
    }

    std::cout << "Result: " << result << std::endl;
    
    return 0;
}