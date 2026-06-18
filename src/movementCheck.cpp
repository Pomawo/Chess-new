#include "../include/global.h"
#include "../include/movementCheck.h"


int whiteKing[2] = {0, 3};
int blackKing[2] = {7, 3};

bool movementCheck() {
    piece = oldPiece;
    if (oldPiece == 'n') {     // *                 KNIGHT
        if (newPiece != 0 && newPiece == (smallPieces)) {
            std::cout << " check 1.1 " << std::endl;
            return false;
        }
        else if (newPiece == 'K') {
            std::cout << " check 2king " << std::endl;
            return false;
        }
        else if (oldTile.x - newTile.x == 1 || oldTile.x - newTile.x == -1) {
            if (oldTile.y - newTile.y == 2 || oldTile.y - newTile.y == -2) {
                std::cout << " check 3.1 " << std::endl;
                return true;
            }
        }
        else if (oldTile.x - newTile.x == 2 || oldTile.x - newTile.x == -2) {
            if (oldTile.y - newTile.y == 1 || oldTile.y - newTile.y == -1) {
                std::cout << " check 3.2 " << std::endl;
                return true;
            }
        }
        else {
            std::cout << " check 4 " << std::endl;
            return false;
        }
    }

    else if (oldPiece == 'k') {     // *                 KING
      std::cout << "efdxhufisdgchdsei9vrsv9iuihsiedfbrehsihkd";
        if (newPiece == (smallPieces)) {
            std::cout << " check 1.1 " << std::endl;
            return false;
        }
        else if (newTile.x != oldTile.x || newTile.y != oldTile.y) {
            for (int a = 1; a > -2; a--) {
                for (int b = 1; b > -2; b--) {
                    if (newTile.y == blackK.y + a && newTile.x == blackK.x + b) { //detecting if our King going to touch enemy's King closest zones          EDIT: Mate you've spelled "closest" as "clothest" :)
                        std::cout << " check 2 " << std::endl;
                        return false;
                    }
                }
            }
            for (int y = 1; y > -2; y--) {
                for (int x = 1; x > -2; x++) {
                    if (newTile.y == oldTile.y + y && newTile.x == oldTile.x + x) {
                        std::cout << " check 3 " << std::endl;
                        whiteKing[0] = whiteK.y;
                        whiteKing[1] = whiteK.x;
                        return true;
                    }
                }
            } 
        }
        else {
            return false;
        }
            std::cout << "scsadawqqdcfdqaSADC";
    }
    
    else if (oldPiece == 'b') {     // *            BISHOP
      std::cout << "fdizxbhjiwfesroiaewjoseifg";
        if (newPiece != 0 && newPiece == (smallPieces) ) {
            std::cout << " check 1.1. No cannibalism allowed. " << std::endl;
            return false;
        }
        else if (abs(newTile.x - oldTile.x) != abs(newTile.y - oldTile.y)) {
            std::cout << " check 1.2. Not diagonal movement. " << std::endl;
            return false;
        }
        else if (newTile.x < oldTile.x && newTile.x < newTile.y) {
             for (int dif = 1; dif < abs(newTile.x - oldTile.x) - 1; dif++) {
                 if(pieces[oldTile.y-dif][oldTile.x-dif] == (smallPieces) || pieces[oldTile.y-dif][oldTile.x-dif] == (bigPieces)) {
                    std::cout << " check 2.1. - - Fail. " << std::endl;
                    return false;
                 }
             }
        }
        else if (newTile.x > oldTile.x && newTile.x > newTile.y) {
             for (int dif = 1; dif < abs(newTile.x - oldTile.x) - 1; dif++) {
                 if(pieces[oldTile.y+dif][oldTile.x+dif] == (smallPieces) || pieces[oldTile.y+dif][oldTile.x+dif] == (bigPieces)) {
                    std::cout << " check 2.2. + + Fail. " << std::endl;
                    return false;
                 }
             }
        }
        else if (newTile.x < oldTile.x && newTile.x > newTile.y) {
             for (int dif = 1; dif < abs(newTile.x - oldTile.x) - 1; dif++) {
                 if(pieces[oldTile.y+dif][oldTile.x-dif] == (smallPieces) || pieces[oldTile.y+dif][oldTile.x-dif] == (bigPieces)) {
                    std::cout << " check 2.3. - + Fail. " << std::endl;
                    return false;
                 }
             }
        }
        else if (newTile.x > oldTile.x && newTile.x < newTile.y) {
             for (int dif = 1; dif < abs(newTile.x - oldTile.x) - 1; dif++) {
                 if(pieces[oldTile.y-dif][oldTile.x+dif] == (smallPieces) || pieces[oldTile.y-dif][oldTile.x+dif] == (bigPieces)) {
                    std::cout << " check 2.4. + - Fail. " << std::endl;
                    return false;
                 }
             }
        }
        else {
            std::cout << " check 3 " << std::endl;
            return true;
        }
    }
    else if (oldPiece == 'r') {     // *                 ROOK
    
    }
    else if (oldPiece == 'q') {     // *                 QUEEN
    
    } 
    else if (oldPiece == 'p') {     // *                 PAWN
    
    }
    std::cout << " All the way through " << std::endl;
    return false;

}
