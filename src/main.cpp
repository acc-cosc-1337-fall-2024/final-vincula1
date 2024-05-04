#include <iostream>
#include <ctime>
#include <cstdlib>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"


int main() 
{
	// Here we initialize the random seed
	std::srand(static_cast<unsigned int>(std::time(0)));

	// Creating two instances of Die
	Die die1, die2;

	// Creating a Shooter instance
	Shooter shooter;

	// Creating a pointer to Roll and an int variable for rolled_value
	Roll* roll;
	int rolled_value;

	// Next, creating a ComeOutPhase instance
	ComeOutPhase come_out_phase;

	// Initializing the first loop :3

	do {
		roll = shooter.throw_dice(die1, die2);
		rolled_value = roll->roll_value();
		std::cout << "Rolled " << rolled_value << ", roll again" << std::endl;
	} while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps);
	
	// Then we display the start of point phase

	std::cout << "Rolled " << rolled_value << " start of point phase" << std::endl;
	std::cout << "Roll until " << rolled_value << " or a 7 is rolled" << std::endl;

	// This is for setting the pointt phase
	int point = rolled_value;
	PointPhase point_phase(point);

	// This is the second phase of the loop ^^
	RollOutcome outcome;
	do {
		roll = shooter.throw_dice(die1, die2);
		rolled_value = roll->roll_value();
		std::cout << "Rolled " << rolled_value << ", roll again" << std::endl;
		outcome = point_phase.get_outcome(roll);
	} while (outcome != RollOutcome::seven_out && outcome != RollOutcome::nopoint);

	// Displaying the end of the point phase
	std::cout << "Rolled " << rolled_value << " end of point phase" << std::endl;

	// Finally, we are now displaying all the rolled values yaayyy
	shooter.display_rolled_values();

	return 0;
}