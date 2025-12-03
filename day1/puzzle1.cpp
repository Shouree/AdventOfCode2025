#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

int main() {
    std::ifstream inputFile("./day1/input1.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int dial = 50;
    std::string line;
    int count = 0;

    while(std::getline(inputFile, line)) {
        if(line[0] == 'L') {
            dial -= std::stoi(line.substr(1));
            dial = (dial % 100 + 100) % 100;
        }
        else if(line[0] == 'R') {
            dial += std::stoi(line.substr(1));
            dial = dial % 100;
        }

        if(dial == 0)
            count++;

    }

    std::cout << "Password: " << count << std::endl;

    return 0;
}