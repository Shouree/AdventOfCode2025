#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

int main() {
    std::ifstream inputFile("./day1/input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int dial = 50;
    std::string line;
    int count = 0;
    int rotations = 0;
    int totalRotations = 0;

    while(std::getline(inputFile, line)) {
        if(line[0] == 'L') {
            int prevDial = dial;
            dial -= std::stoi(line.substr(1));
            rotations = std::max(0, (int)floor(std::abs(dial) / 100));
            if(dial < 0  && prevDial > 0 && dial != prevDial)
                rotations++;
            dial = (dial % 100 + 100) % 100;
            
        }
        else if(line[0] == 'R') {
            dial += std::stoi(line.substr(1));
            if(dial > 100)
                rotations = std::max(0, (int)floor(std::abs(dial) / 100));
            dial = dial % 100;
        }
    
        count += rotations;

        if(dial == 0 && rotations == 0)
            count++;

        rotations = 0;

    }

    std::cout << "Password: " << count << std::endl;

    return 0;
}