//
#include "die.h"
#include <cstdlib>
#include <ctime>

Die::Die() : current_value(0) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

int Die::roll() const {
    if (current_value != 0) {
        return current_value;
    }
    return std::rand() % sides + 1;
}

void Die::set_value(int value) {
    if (value >= 1 && value <= sides) {
        current_value = value;
    }
}