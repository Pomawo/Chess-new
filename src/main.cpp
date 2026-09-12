#include "../include/main.h"
#include "../include/global.h"
#include "../include/movementCheck.h"


/*




*/


void log() {
    std::cout <<std::endl << std::endl << std::endl << "LOG: " << std::endl << std::endl << "oldTile.x: " << oldTile.x << ", oldTile.y: " << oldTile.y << ", old piece: " << oldPiece << std::endl << "newTile.x: " << newTile.x << ", newTile.y: " << newTile.y << ", new piece: " << newPiece << std::endl << "movementCheck result:" << movementCheck() << std::endl;


}

void replace() {
    newPiece = oldPiece;
    oldPiece = 0;
};

void drawField() {
    for (int i = 0; i < 33; i++) {
        std::cout << '-';
    }
    std::cout << std::endl;
    for (int y = 0; y < 8; y++){
        std::cout << '|';
        for(int x = 0; x < 8; x++) {
            if (pieces[y][x] == 0) {
                if (x == 0) {
                    std::cout << ' ' << field[y][x] << ' ' << '|';
                }
                else {
                    std::cout << ' ' << field[y][x] << ' ' << '|';
                }
            }
            else {
                std::cout << ' ' << pieces[y][x] << ' ' << '|';
            }
        }
        std::cout << std::endl;
        for (int i = 0; i < 33; i++) {
            std::cout << '-';
        }
        std::cout << std::endl;
    }
};

int main() {
// whiteK.y = whiteKing[0];         //What is this supposed to be mate? I am too sleepy to figure out :/
// whiteK.x = whiteKing[1];
// blackK.y = blackKing[0];
// blackK.x = blackKing[1];


while (1) {
    log();
    std::cin >> oldTile.x >> oldTile.y >> newTile.x >> newTile.y;
    if(std::cin.fail()) {
        std::cout << "Wrong input. Input must be a number. Err 01" << std::endl;// To change as we go
        std::cin.clear();
        std::cin.ignore();
    } else {
        if (movementCheck()) {
            replace();
        }
        else {
            std::cout << "Incorrect input. Try again. Err 02\n";
            log();
        }
        drawField();
    };
};
};

