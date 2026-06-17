#include <iostream>
#include <cmath>

#define oldPiece pieces[oldTile.y][oldTile.x]
#define newPiece pieces[newTile.y][newTile.x]
#define smallPieces (piece) == 'r'| (piece) == 'n'| (piece) == 'b'| (piece) == 'k'| (piece) == 'q'| (piece) == 'p'
#define bigPieces (piece) == 'R'| (piece) == 'N'| (piece) == 'B'| (piece) == 'K'| (piece) == 'Q'| (piece) == 'P'

/*
-----
| P |
-----
| R |
-----

! Download "Better Comments" extension from Aarom Bondit

TODO: Зробити нормальний інпут. Я хотів аби гравець міг написати "Board" та виконалась функція drawField(). Для цього ми будемо записувати std::cin >> input; нову змінну. Тоді перевіримо її на технічні терміни, такі як я запропонував "Board", і тоді розіб'ємо ввід гравця у форматі "a2>a4" чи подібний, і перекладемо на нашу систему координат, що зараз є. 

? Я не знаю що я собі думаю, не дрімаючи в 2 години ночі в день НМТ. Я просто не міг заснути, напевно 

*/

int whiteKing[2] = {0, 3};
int blackKing[2] = {7, 3};

struct {
    int x;
    int y;
} whiteK, blackK;

struct {
    int x;
    int y;
} oldTile, newTile;

char piece; 

char field[8][8] = {
    {' ','#',' ','#',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' '},
    {' ','#',' ','#',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' '},
    {' ','#',' ','#',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' '},
    {' ','#',' ','#',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' '}
};
char pieces[8][8] = {
    /*0*/ {'r','n','b', 0,'q','b','n','r'}, /*char = 8*/
    /*1*/ {'p','p','p','p','p','p','p','p'}, /*char = 7*/
    /*2*/ { 0,  0,  0,  0,  0,  0,  0,  0 }, /*char = 6*/
    /*3*/ { 0,'k',  'b',  0,  0,  0,  0,  0 }, /*char = 5*/
    /*4*/ { 0,  0,  0,  0,  0,  0,  0,  0 }, /*char = 4*/
    /*5*/ { 0,  0,  0,  0,  0,  0,  0,  0 }, /*char = 3*/
    /*6*/ {'P','P','P','P','P','P','P','P'}, /*char = 2*/
    /*7*/ {'R','N','B','K','Q','B','N','R'}  /*char = 1*/ // 8 - char
};

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

void replace() {
    newPiece = oldPiece;
    oldPiece = 0;
};

void input() {
    try {
        throw 404;
    }
    catch (...){
        std::cout << "Incorrect input";
    }
};

void log() {
    std::cout <<std::endl << std::endl << std::endl << "LOG: " << std::endl << std::endl << "oldTile.x: " << oldTile.x << ", oldTile.y: " << oldTile.y << ", old piece: " << oldPiece << std::endl << "newTile.x: " << newTile.x << ", newTile.y: " << newTile.y << ", new piece: " << newPiece << std::endl << "movementCheck result:" << movementCheck() << std::endl;


}

int main() {
whiteK.y = whiteKing[0];
whiteK.x = whiteKing[1];
blackK.y = blackKing[0];
blackK.x = blackKing[1];


drawField();
while (1) {
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

