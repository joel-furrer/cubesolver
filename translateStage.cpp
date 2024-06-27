//translateStage.cpp

#include "translateStage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Function to read the cube data from a file and store it in the provided cube array
//Returns true if the file is successfully read and false otherwise
bool translateStage(const std::string& filename, char cube[6][3][3]) {
    //Attempt to open the file
    ifstream file(filename);
    if (!file) {
        cerr << "[Error: Unable to open file " << filename << "]" << endl;
        return false;
    }

    string line;
    int side = 0, row = 0;
    //Read each line of the file
    while (getline(file, line)) {
        //Check for empty line to switch to next side
        if (line.empty()) {
            side++;
            row = 0;
            continue;
        }

        istringstream iss(line);
        //Read and store the colors in the cube array
        for (int col = 0; col < 3; ++col) {
            if (!(iss >> cube[side][row][col])) {
                cerr << "[Error: Reading file " << filename << " at side " << side << ", row " << row << "]" << endl;
                return false;
            }
        }
        row++;
    }

    file.close();
    cout << "--------------------------------------------------------------" << endl;
    cout << "Stage translated successfully from " << filename << endl;
    return true;
}
