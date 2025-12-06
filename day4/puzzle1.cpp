#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("./day4/input.txt");

    if(!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<char>> grid;

    while(std::getline(inputFile, line)) {
       grid.emplace_back(line.begin(), line.end());
    }

    int rows = grid.size();
    int columns = grid[0].size();
    int accessible = 0;

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            int counter = 0;
            
            if(grid[i][j] != '@')
                continue;
            for(int di = -1; di <= 1; ++di) {
                for(int dj = -1; dj <= 1; ++dj) {
                    if(di == 0 && dj == 0)
                        continue;
                    
                    int ni = i + di;
                    int nj = j + dj;
                    if(ni >= 0 && ni < rows &&
                       nj >= 0 && nj < columns) {
                        if(grid[ni][nj] == '@' || grid[ni][nj] == 'x')
                            counter++;
                       }
                    
                    if(counter >= 4)
                        break;
                }

                if(counter >= 4)
                        break;
            }

            if(counter < 4)
                accessible++;
        }
    }

    std::cout << "Number of accessible rolls: " << accessible << std::endl;

    return 0;
}