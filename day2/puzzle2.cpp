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
            
            for(size_t j = 1; j <= iStr.size() / 2; ++j) {
                if(iStr.size() % j != 0)
                    continue;
                
                bool match = true;
                for(size_t k = j; k < iStr.size(); k += j) {
                    if(iStr.substr(0, j) != iStr.substr(k, j)){
                        match = false;
                        break;
                    }
                }
                
                if(match) {
                    result += i;
                    break;
                }
            }
        }
    }

    std::cout << "Result: " << result << std::endl;
    return 0;
}