#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Create empty 3D cube array
char cube[6][3][3];

string sides[6] = {"Yellow", "Orange", "White", "Red", "Green", "Blue"};

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
    // Short introduction
    cout << "Welcome to the CubeSolver. For all following steps assume Yellow is the Top," << endl;
    cout << "White the Bottom and Orange the front of the cube" << endl;
    cout << "--------------------------------------------------------------" << endl;

    // Iterate through the sides
    for (int i = 0; i < 6; i++) {
        cout << "Name all colors for the " << sides[i] << " side:" << endl;

        // Iterate through the rows of the side
        for (int j = 0; j < 3; j++) {
            cout << "Name all 3 colors from left to right for the " << j+1 << " row: ";
            char left, middle, right;
            while (true) {
                cin >> left >> middle >> right;
                if (validateInput(left) && validateInput(middle) && validateInput(right)) {
                    break;
                } else {
                    cout << "Invalid input, try again. Enter 3 valid colors (Y, O, W, R, G, B): ";
                }
            }
            cube[i][j][0] = left;
            cube[i][j][1] = middle;
            cube[i][j][2] = right;
        }
    }

    // Save cube state to a text file
    ofstream file("cube_stages/stage_0.txt");
    if (file.is_open()) {
        file << "{\n";
        for (int i = 0; i < 6; i++) {
            file << "    {\n";
            file << "        {'" << cube[i][0][0] << "', '" << cube[i][0][1] << "', '" << cube[i][0][2] << "'},\n";
            file << "        {'" << cube[i][1][0] << "', '" << cube[i][1][1] << "', '" << cube[i][1][2] << "'},\n";
            file << "        {'" << cube[i][2][0] << "', '" << cube[i][2][1] << "', '" << cube[i][2][2] << "'}\n";
            if (i < 5) {
                file << "    }, // " << sides[i] << " side\n";
            } else {
                file << "    }  // " << sides[i] << " side\n";
            }
        }
        file << "}\n";
        file.close();
        cout << "Cube state saved to cube_stages/stage_0.txt" << endl;
    } else {
        cerr << "Unable to open file" << endl;
    }

    return 0;
}
