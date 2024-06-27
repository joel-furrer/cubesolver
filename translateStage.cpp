#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool translateStage(const string& inputFile, char cube[6][3][3]) {
    cout << "Inside translateStage function." << endl;  // Debugging-Ausgabe hinzufügen

    ifstream file(inputFile);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << inputFile << endl;
        return false;
    }

    int side = 0;
    while (side < 6) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char color;
                if (!(file >> color)) {
                    cerr << "Error reading color from file." << endl;
                    file.close();
                    return false;
                }
                cube[side][i][j] = color;
                cout << "Cube[" << side << "][" << i << "][" << j << "] = " << cube[side][i][j] << endl;  // Debugging-Ausgabe hinzufügen
            }
        }
        ++side;
    }

    file.close();
    return true;
}
