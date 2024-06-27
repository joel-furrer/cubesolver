// stageValidator.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if all six colors appear exactly 9 times
bool validateColorCounts(char cube[6][3][3]) {
    int count[6] = {0}; // Array to count occurrences of each color (Y, O, W, R, G, B)

    // Count occurrences of each color
    for (int side = 0; side < 6; ++side) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                char color = cube[side][row][col];
                if (color == 'Y') count[0]++;
                else if (color == 'O') count[1]++;
                else if (color == 'W') count[2]++;
                else if (color == 'R') count[3]++;
                else if (color == 'G') count[4]++;
                else if (color == 'B') count[5]++;
            }
        }
    }

    // Check if each color appears exactly 9 times
    for (int i = 0; i < 6; ++i) {
        if (count[i] != 9) {
            cout << "[Validation Failed] Color " << (char)('Y' + i) << " appears " << count[i] << " times instead of 9." << endl;
            return false;
        }
    }

    cout << "[Validation Passed] All colors appear exactly 9 times." << endl;
    return true;
}

// Function to check if the center pieces of each side are correct
bool validateCenterPieces(char cube[6][3][3]) {
    char centers[6] = {'Y', 'O', 'W', 'R', 'G', 'B'};
    bool isValid = true;

    for (int side = 0; side < 6; ++side) {
        char center = cube[side][1][1];
        if (center != centers[side]) {
            cout << "[Validation Failed] Center piece of " << (char)('Y' + side) << " side is incorrect." << endl;
            isValid = false;
        }
    }

    if (isValid) {
        cout << "[Validation Passed] All center pieces are correct." << endl;
    }

    return isValid;
}

int main() {
    cout << "Starting stageValidator program." << endl;

    char cube[6][3][3];

    // Read cube state from stage_0.txt
    ifstream file("cube_stages/stage_0.txt");
    if (!file.is_open()) {
        cerr << "[Error] Unable to open file: cube_stages/stage_0.txt" << endl;
        return 1;
    }

    // Read cube state into the cube array
    for (int side = 0; side < 6; ++side) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (!(file >> cube[side][row][col])) {
                    cerr << "[Error] Failed to read cube state from file." << endl;
                    return 1;
                }
            }
        }
    }
    file.close();

    cout << "Cube state loaded from cube_stages/stage_0.txt." << endl;

    // Validate cube colors and center pieces
    if (validateColorCounts(cube) && validateCenterPieces(cube)) {
        cout << "Cube validation successful." << endl;
    } else {
        cout << "Cube validation failed." << endl;
    }

    return 0;
}
