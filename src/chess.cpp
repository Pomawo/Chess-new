#include "../include/chess.h"
#include "../include/global.h"
#include "../include/movementCheck.h"
#include "../include/drawField.h"


/*



TODO: Move input() into separate files, making it proper. 

*/


void log() {
    std::cout <<std::endl << std::endl << std::endl << "LOG: " << std::endl << std::endl << "oldTile.x: " << oldTile.x << ", oldTile.y: " << oldTile.y << ", old piece: " << oldPiece << std::endl << "newTile.x: " << newTile.x << ", newTile.y: " << newTile.y << ", new piece: " << newPiece << std::endl << "movementCheck result:" << movementCheck() << std::endl;


}

void replace() {
    newPiece = oldPiece;
    oldPiece = 0;
};


int main() {
whiteK.y = whiteKing[0];
whiteK.x = whiteKing[1];
blackK.y = blackKing[0];
blackK.x = blackKing[1];


drawField();
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

