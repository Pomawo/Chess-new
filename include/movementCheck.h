#ifndef LEGAL_MOVE_H
#define LEGAL_MOVE_H

bool movementCheck();

int whiteKing[2];
int blackKing[2];

struct {
    int x;
    int y;
} whiteK, blackK;

#endif