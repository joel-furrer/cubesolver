//stageValidator.cpp

#include <iostream>
#include "translateStage.h"

using namespace std;

//Function to validate if the cube configuration is possible
bool validateCube(char cube[6][3][3]) {
    const int max_count = 9;
    int counts[6] = {0}; //Array to count occurrences of each color (Y, O, W, R, G, B)

    //Check each side of the cube
    for (int side = 0; side < 6; ++side) {
        //Reset counts for each side
        counts[0] = counts[1] = counts[2] = counts[3] = counts[4] = counts[5] = 0;

        //Validate the middle piece of each side (second row)
        char middle_piece = cube[side][1][1];
        switch (middle_piece) {
            case 'Y': counts[0]++; break;
            case 'O': counts[1]++; break;
            case 'W': counts[2]++; break;
            case 'R': counts[3]++; break;
            case 'G': counts[4]++; break;
            case 'B': counts[5]++; break;
            default: 
                cout << "[Error: Invalid middle piece color on side " << side << "]" << endl;
                return false; //Invalid color
        }

        //Count all pieces on this side
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                char color = cube[side][row][col];
                switch (color) {
                    case 'Y': counts[0]++; break;
                    case 'O': counts[1]++; break;
                    case 'W': counts[2]++; break;
                    case 'R': counts[3]++; break;
                    case 'G': counts[4]++; break;
                    case 'B': counts[5]++; break;
                    default: 
                        cout << "[Error: Invalid color on side " << side << ", row " << row << ", col " << col << "]" << endl;
                        return false; //Invalid color
                }
            }
        }

        //Check if all colors have exactly 9 pieces on this side
        for (int i = 0; i < 6; ++i) {
            if (counts[i] != max_count) {
                cout << "[Error: Color count mismatch on side " << side << "]" << endl;
                return false;
            }
        }
    }

    //Check the order of middle pieces across all sides
    if (!(counts[0] == 9 && counts[1] == 9 && counts[2] == 9 && counts[3] == 9 && counts[4] == 9 && counts[5] == 9)) {
        cout << "[Error: Total color count mismatch]" << endl;
        return false;
    }

    return true;
}

int main() {
    //Cube array to store the state
    char cube[6][3][3];
    
    //Translate the stage file to the cube array
    if (!translateStage("cube_stages/stage_0.txt", cube)) {
        cerr << "[Error: Failed to translate stage.]" << endl;
        return 1;
    }

    //Validate the cube configuration
    if (validateCube(cube)) {
        cout << "--------------------------------------------------------------" << endl;
        cout << "Cube configuration is valid." << endl;
    } else {
        cout << "--------------------------------------------------------------" << endl;
        cout << "[Error: Cube configuration is invalid.]" << endl;
    }

    return 0;
}
