#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;



enum Direction {
    STOP,
    LEFT,
    UP,
    RIGHT,
    DOWN
} dir, newDir;

enum GameState {
    PLAYING,
    GAME_OVER
} gamestate;
enum GameState gameState = PLAYING;

enum fieldSize {
    SMALL = 12,
    MEDIUM = 22,
    BIG = 42
} fieldsize;

struct Body {
    int y;
    int x;
};

int height;
int width;

void fieldSize() {
    char fieldS;

    cout << "In this game you can choose size of the field. \nType S - for small, M - for medium and B - for big size: ";
    cin >> fieldS;
    if (fieldS == 'S') {
        fieldsize = SMALL;
        height = fieldsize;
        width = fieldsize;
    }
    else if (fieldS == 'M') {
        fieldsize = MEDIUM;
        height = fieldsize;
        width = fieldsize;
    }
    else {
        fieldsize = BIG;
        height = fieldsize;
        width = fieldsize;
    }
}

int maxSnakeSize = ((height - 2) * (width - 2)) - 1;

vector<Body> snakeBody(maxSnakeSize);
Body appleCoords;
int snakeLength = (fieldsize - 2) / 5;
int score;
char inputStart;

void generateApple() {
    appleCoords.x = (rand() % (fieldsize - 2)) + 1;
    appleCoords.y = (rand() % (fieldsize - 2)) + 1;
    for (int i = 0; i < snakeLength; i++) {
        if (snakeBody[i].x == appleCoords.x &&
            snakeBody[i].y == appleCoords.y) {
            appleCoords.x = (rand() % (fieldsize - 2)) + 1;
            appleCoords.y = (rand() % (fieldsize - 2)) + 1;
        }
    }
}

void drawField() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
                cout << "# ";
            }
            else if (x == snakeBody[0].x && y == snakeBody[0].y) {
                cout << "O ";
            }
            else if (x == appleCoords.x && y == appleCoords.y) {
                cout << "F ";
            }
            else {
                bool printed = false;
                for (int i = 1; i < snakeBody.size(); i++) {
                    if (snakeBody[i].x == x && snakeBody[i].y == y) {
                        cout << "o ";
                        printed = true;
                    }
                }
                if (!printed) cout << " " << " ";
            }
        }
        cout << "\n";
    }
};

void setStartPoint(int x, int y) {
    snakeBody[0].x = x;
    snakeBody[0].y = y;
}

void moveMent() {
    if (GetSystemMetrics(SM_SWAPBUTTON)) {
    }
    else if (GetAsyncKeyState('S')) {
        newDir = DOWN;
    }
    else if (GetAsyncKeyState('A')) {
        newDir = LEFT;
    }
    else if (GetAsyncKeyState('W')) {
        newDir = UP;
    }
    else if (GetAsyncKeyState('D')) {
        newDir = RIGHT;
    }
}

void checkDir() {
    if (dir == DOWN && newDir == UP || 
        dir == UP && newDir == DOWN || 
        dir == LEFT && newDir == RIGHT || 
        dir == RIGHT && newDir == LEFT) {
    }
    else {
        dir = newDir;
    }
}

void calculateHead() {
    if (dir == DOWN) {
        snakeBody[0].y++;
    }
    else if (dir == UP) {
        snakeBody[0].y--;
    }
    else if (dir == LEFT) {
        snakeBody[0].x--;
    }
    else if (dir == RIGHT) {
        snakeBody[0].x++;
    }
}

void checkWall() {
    if (snakeBody[0].x >= width - 1) {
        snakeBody[0].x = 1;
    }
    else if (snakeBody[0].x <= 0) {
        snakeBody[0].x = width - 2;
    }
    else if (snakeBody[0].y >= height - 1) {
        snakeBody[0].y = 1;
    }
    else if (snakeBody[0].y <= 0) {
        snakeBody[0].y = height - 2;
    }
}

void dinnerApple() {
    if (appleCoords.x == snakeBody[0].x && appleCoords.y == snakeBody[0].y) {
        snakeLength++;
        score++;
        generateApple();
    }
}

void increasingSnakeBodyLength() {
    for (int i = snakeLength; i > 0; i--) {
        snakeBody[i].x = snakeBody[i - 1].x;
        snakeBody[i].y = snakeBody[i - 1].y;
    }
}

void snakeBodyCollision() {
    char winCharacter = (score <= 25 && score > 0) ? 'L' : 
        (score <= maxSnakeSize / 5 && score > 25) ? 48 : 
        (score <= maxSnakeSize / 2 && score > maxSnakeSize / 5) ? 177 : 
        (score == maxSnakeSize) ? 253 : 26;

    for (int i = snakeLength; i > 1; i--) {
        if (snakeBody[0].x == snakeBody[i].x && snakeBody[0].y == snakeBody[i].y) {
           cout << "GAME OVER!\nYour score: " << score << " " << winCharacter;
           gamestate = GAME_OVER;
        }
    }
}

int main() {
    using namespace std::this_thread;
    using namespace std::chrono;

    string start;
    short stupidMoronScore = 0;
    srand(time(0));

    cout << "This is Snake Game. You will to start? Type \"Yes\" if you want and \"No\" \n";
    while (true) {
        cin >> start;

        if (start == "Yes") {

            fieldSize();
            
            setStartPoint(5, 5);

            appleCoords.x;
            appleCoords.y;
            generateApple();
            dir = DOWN;

            while (gamestate == PLAYING) {
                
                moveMent();
                checkDir();
                dinnerApple();
                calculateHead();
                checkWall();
                increasingSnakeBodyLength();
                drawField();
                snakeBodyCollision();
                cout << endl;
                for (int i = 0; i < snakeLength; i++) {
                    cout << i << ": x " << snakeBody[i].x << ", y " << snakeBody[i].y << endl;
                }

                sleep_for(nanoseconds(350'000'000));
            }
            cout << "\n\nYou will to continue? Type \"Yes\" if you want and \"No\"\n";
        }
        else if (start == "No") {
            cout << "See you next time!";
            break;
        }
        else {
            cout << "You have to type only \"Yes\" or \"No\", try again: \n";
            stupidMoronScore++;
        }
        if (stupidMoronScore == 10) {
            cout << "I don't mean to offend you, but you are stupid piece of retard!";
            break;
        }
    }

    return 0;
}