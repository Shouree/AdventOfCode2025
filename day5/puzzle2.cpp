#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("./day5/input.txt");

    if(!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::pair<uint64_t, uint64_t>> ranges;
    
    while(std::getline(inputFile, line)) {
        if(line.empty())
            continue;
        
        int dashPos = line.find('-');
        uint64_t start = std::stoull(line.substr(0, dashPos));
        uint64_t end = std::stoull(line.substr(dashPos + 1));
        ranges.push_back({start, end});
    }

    std::sort(ranges.begin(), ranges.end());

    std::vector<std::pair<uint64_t, uint64_t>> mergedRanges;
    for(const auto& range: ranges) {
        if(mergedRanges.empty() || range.first > mergedRanges.back().second)
            mergedRanges.push_back(range);
        else
            mergedRanges.back().second = std::max(mergedRanges.back().second, range.second);
    }

    uint64_t amountFresh = 0;

    for(const auto& range: mergedRanges) {
        amountFresh += range.second - range.first + 1;
    }
        

    std::cout << "Amount of fresh ingredients available: " << amountFresh << std::endl;
    return 0;
}