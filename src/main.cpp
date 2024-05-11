#include <iostream>
#include <ctime>
#include <cstdlib>
#include "die.h"
#include "shooter.h"
#include "roll.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() {
    // Here we are initializing a random seed
    srand(static_cast<unsigned>(time(0)));

    // Create two instances of Die
    Die die1, die2;

    // Create a Shooter instance
    Shooter shooter;

    // Create a pointer to Roll and an int variable for rolled_value
    Roll* roll;
    int rolled_value;

    // Create a ComeOutPhase instance
    ComeOutPhase come_out_phase;

    // First phase loop
    while (true) {
        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
        auto outcome = come_out_phase.get_outcome(roll);
        
        if (outcome == RollOutcome::natural || outcome == RollOutcome::craps) {
            std::cout << "Rolled " << rolled_value << ", roll again" << std::endl;
        } else {
            std::cout << "Rolled " << rolled_value << " start of point phase" << std::endl;
            break;  // This is to break when its not natural or craps
        }
    }

    std::cout << "Roll until " << rolled_value << " or a 7 is rolled" << std::endl;

    // Set point for point phase
    int point = rolled_value;
    PointPhase point_phase(point);

    // Second phase loop
    while (true) {
        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
        auto outcome = point_phase.get_outcome(roll);
        
        if (outcome == RollOutcome::point || outcome == RollOutcome::seven_out) {
            std::cout << "Rolled " << rolled_value << " end of point phase" << std::endl;
            break;  // We exit here if 7 or poin is made
        } else {
            std::cout << "Rolled " << rolled_value << ", roll again" << std::endl;
        }
    }

    // Display all rolled values :3
    shooter.display_rolled_values();

    return 0;
}
