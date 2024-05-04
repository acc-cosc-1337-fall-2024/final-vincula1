//
#include "die.h"
#include <cstdlib>
#include <ctime>

Die::Die() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

int Die::roll() const {
    return std::rand() % sides + 1;
}