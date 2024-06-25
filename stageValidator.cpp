//stageValidator
#include <iostream>
#include "translateStage.h"

int main() {
    char cube[6][3][3];
    translateStage("cube_stages/stage_0.txt", cube);

    // Output the cube to verify
    for (int side = 0; side < 6; ++side) {
        std::cout << "Side " << side << ":\n";
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                std::cout << cube[side][row][col] << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
