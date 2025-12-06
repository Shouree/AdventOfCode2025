#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

int main() {
    std::ifstream inputFile("./day5/input.txt");

    if(!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::pair<uint64_t, uint64_t>> ranges;
    int amountFresh = 0;
    while(std::getline(inputFile, line)) {
        if(line.empty())
            continue;
        
        int dashPos = line.find('-');

        if(dashPos == std::string::npos) {
            uint64_t id = std::stoull(line);
            
            for(const auto& i : ranges) {
                if(id >= i.first && id <= i.second) {
                    amountFresh++;
                    break;
                }
                    
            }
        }
        else {
            uint64_t start = std::stoull(line.substr(0, dashPos));
            uint64_t end = std::stoull(line.substr(dashPos + 1));
            ranges.push_back(std::make_pair(start, end));
        }
    }

    std::cout << "Amount of fresh ingredients available: " << amountFresh << std::endl;
    return 0;
}