#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>

int main() {
    std::ifstream inputFile("./day6/input.txt");

    if(!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<std::string>> problems;
    while(std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<std::string> row;
        std::string token;
        while (iss >> token) {
            row.push_back(token);
        }
        problems.push_back(row);
    }

    int rows = problems.size();
    int columns = problems[0].size();
    uint64_t total = 0;
    for(int j = 0; j < columns; ++j) {
        std::string operation = problems[rows - 1][j];
        uint64_t value = std::stoull(problems[rows - 2][j]);

        for(int i = rows - 3; i >= 0; --i) {
            if(operation == "+")
                value = value + std::stoull(problems[i][j]);
            else if(operation == "*") {
                value = value * std::stoull(problems[i][j]);
            }
            
        }

        total += value;
    }

    std::cout << total << std::endl;
    return 0;
}