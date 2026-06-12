#include <ctime>
#include <iostream>

int main() {
    time_t timestamp;
    struct tm datetime = *localtime(&timestamp);

    if (datetime.tm_year == 29) {
        std::cout << "DOOM";
    }
    else {
        std::cout << "Not DOOM";
    }

    return 0;
}