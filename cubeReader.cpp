// cubeReader.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>  // for numeric_limits
#include <ios>     // for streamsize

using namespace std;

// Create empty 3D cube array
char cube[6][3][3];

string sides[6] = {"Yellow", "Orange", "White", "Red", "Green", "Blue"};
string overSides[6] = {"Red", "Yellow", "Orange", "Yellow", "Yellow", "Yellow"};

// Function to convert input to uppercase and validate
bool validateInput(char &input) {
    input = toupper(input);
    const char valid_input[6] = {'Y', 'O', 'W', 'R', 'G', 'B'};
    for (char c : valid_input) {
        if (input == c) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Welcome to the CubeSolver." << endl;
    cout << "Please input the colors of each side of the Rubik's Cube following these instructions:" << endl;
    cout << "Assume the cube is oriented with Yellow on top, Orange in front, and the colors around it as follows:" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < 6; i++) {
        cout << "Enter colors for the " << sides[i] << " side." << endl;
        cout << "View it as the side directly under " << overSides[i] << "." << endl;
        cout << "Enter colors starting from the top-left to bottom-left, row by row." << endl;

        for (int j = 0; j < 3; j++) {
            cout << "Row " << j + 1 << ": ";
            char left, middle, right;
            while (true) {
                if (!(cin >> left >> middle >> right)) {
                    cin.clear(); // clear error state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard incorrect input

                    cout << "[Error: Invalid input] Enter exactly 3 valid colors (Y, O, W, R, G, B): ";
                    continue;
                }

                if (!validateInput(left) || !validateInput(middle) || !validateInput(right)) {
                    cout << "[Error: Invalid colors] Enter valid colors (Y, O, W, R, G, B): ";
                    continue;
                }

                if (cin.get() != '\n') {
                    cout << "[Error: Too many characters] Enter exactly 3 colors (Y, O, W, R, G, B): ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard extra input
                    continue;
                }

                break;
            }

            cube[i][j][0] = left;
            cube[i][j][1] = middle;
            cube[i][j][2] = right;
        }
    }

    ofstream file("cube_stages/stage_0.txt");
    if (file.is_open()) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    file << cube[i][j][k] << ' ';
                }
                file << '\n';
            }
            file << '\n';
        }
        file.close();
        cout << "Cube state saved to cube_stages/stage_0.txt" << endl;
    } else {
        cerr << "[Error: Unable to open file] cube_stages/stage_0.txt" << endl;
    }

    return 0;
}
