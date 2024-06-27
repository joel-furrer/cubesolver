// translateStage.cpp
#include "translateStage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Function to read the cube data from a file and store it in the provided cube array
// Returns true if the file is successfully read and false otherwise
bool translateStage(const std::string& filename, char cube[6][3][3]) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return false;
    }

    std::string line;
    int side = 0, row = 0;
    while (std::getline(file, line)) {
        if (line.empty()) {
            side++;
            row = 0;
            continue;
        }

        std::istringstream iss(line);
        for (int col = 0; col < 3; ++col) {
            if (!(iss >> cube[side][row][col])) {
                std::cerr << "Error reading file " << filename << " at side " << side << ", row " << row << std::endl;
                return false;
            }
        }
        row++;
    }

    file.close();
    std::cout << "translateStage successful" << std::endl;
    return true;
}
