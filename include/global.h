#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <cmath>

#define oldPiece pieces[oldTile.y][oldTile.x]
#define newPiece pieces[newTile.y][newTile.x]
#define smallPieces (piece) == 'r'| (piece) == 'n'| (piece) == 'b'| (piece) == 'k'| (piece) == 'q'| (piece) == 'p'
#define bigPieces   (piece) == 'R'| (piece) == 'N'| (piece) == 'B'| (piece) == 'K'| (piece) == 'Q'| (piece) == 'P'


extern char field[8][8];
extern char pieces[8][8];

struct {
    int x;
    int y;
} oldTile, newTile;

char piece; 


#endif