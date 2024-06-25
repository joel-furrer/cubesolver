//translateStage.cpp
#include "translateStage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void translateStage(const std::string& filename, char cube[6][3][3]) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
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
            iss >> cube[side][row][col];
        }
        row++;
    }

    file.close();
}
