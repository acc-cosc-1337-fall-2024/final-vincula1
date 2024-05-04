//
#include "shooter.h"
#include <iostream>

Roll* Shooter::throw_dice(Die& die1, Die& die2) {
    Roll* newRoll = new Roll(die1, die2);
    newRoll->roll_dice();
    rolls.push_back(newRoll);
    return newRoll;

}


void Shooter::display_rolled_values() {
    for (const Roll* roll : rolls) {
        std::cout << "Rolled value: " << roll->roll_value() << std::endl;
    }
}

Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;
    }
    rolls.clear();
}