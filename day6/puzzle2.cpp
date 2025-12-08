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
    std::vector<std::string> lines;
    std::vector<std::vector<std::string>> problems;
    while(std::getline(inputFile, line)) {
        lines.push_back(line);
        std::istringstream iss(line);
        std::vector<std::string> row;
        std::string token;
        while (iss >> token) {
            row.push_back(token);
        }
        problems.push_back(row);
    }

    std::vector<std::vector<char>> chars;

    for(int i = 0; i < lines.size() - 1; ++i)
        chars.push_back(std::vector<char>(lines[i].begin(), lines[i].end()));
    
    std::vector<char> operations;
    std::string opStr = lines[lines.size() - 1];

    for(const char c : opStr) {
        if(c != ' ')
            operations.push_back(c);
    }

    int rows = chars.size();
    int columns = chars[0].size();
    
    std::vector<std::vector<int>> cephalopodVec(columns);
    for(int j = 0; j < columns; ++j) {
        std::string columnValue;
        
        for(int i = 0; i < rows; ++i) {
            char c = chars[i][j];
            
            if(c != ' ')
                columnValue += c;
        }
        
        try {
            cephalopodVec[j].push_back(std::stoi(columnValue));
        }
        catch(const std::exception& e) {
            continue;
        }  
    }
    
    uint64_t currValue = 0;
    uint64_t total = 0;
    int operationIndex = 0;
    for(const auto& intVec : cephalopodVec) {
        if(intVec.empty()) {
            total += currValue;
            currValue = 0;
            operationIndex++;
            continue;
        }
        
        for(const auto& i : intVec) {
            if(currValue == 0)
                currValue = i;
            else if(operations[operationIndex] == '+')
                    currValue += i;
            else if(operations[operationIndex] == '*') {
                    currValue *= i;
            }
        }
    }

    total += currValue;
    std::cout << total << std::endl;

    return 0;

}