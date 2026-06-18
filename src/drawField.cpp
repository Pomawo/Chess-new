#include <iostream>
#include <cmath>

#include "../include/global.h"
#include "../include/legal_move.h"

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