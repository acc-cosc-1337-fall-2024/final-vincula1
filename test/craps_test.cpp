#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "point_phase.h"
#include "come_out_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test case to assert die rolls to return value", "[Die]") {
    Die die;
    int result = die.roll();
    REQUIRE(result >= 1);
    REQUIRE(result <= 6);
}

TEST_CASE("Rolling a dice between 10 times to see if it returns value 1-6", "[Die]") {
    Die die;

    SECTION("Die roll test") {
        for (int i = 0; i < 10; i++) {
            int result = die.roll();
            REQUIRE(result >= 1);
            REQUIRE(result <= 6);
        }
    }
}


TEST_CASE("Test case to test roll for value 2 and 12", "[Die]") {
    Die die1, die2;
    Roll roll(die1, die2);
    roll.roll_dice();
    int result = roll.roll_value();
    REQUIRE(result >= 1);
    REQUIRE(result <= 12);
}

TEST_CASE("Testing die rolls between 2 and 12 , 10 rolls", "[Roll]") {
    Die die1, die2;
    Roll roll(die1, die2);

    SECTION("Verify dice roll values") {
        for (int i = 0; i < 10; i++) {
            roll.roll_dice();
            int result = roll.roll_value();
            REQUIRE(result >= 2);
            REQUIRE(result <= 12);
        }
    }
}

TEST_CASE("Testing shooter throw for valid values between 2 and 12", "[Shooter]") {
    Die die1, die2;
    Shooter shooter;

    Roll* roll = shooter.throw_dice(die1, die2);
    int result = roll->roll_value();
    REQUIRE(result >= 2);
    REQUIRE(result <= 12);
}

TEST_CASE("Testing shooter throw for valid values between 2 and 12, 10 rolls") {
    Die die1, die2;
    Shooter shooter;

    SECTION("Verify dice roll values") {
        for (int i = 0; i < 10; i++) {
            Roll* roll = shooter.throw_dice(die1, die2);
            int result = roll->roll_value();
            REQUIRE(result >= 2);
            REQUIRE(result <= 12);
        }
    }
}

TEST_CASE("ComeOutPhase get outcomes", "[ComeOutPhase]") {
    Die die1, die2;
    ComeOutPhase comeOutPhase;
    Roll roll(die1, die2);

    SECTION("Natural outcome") {
        die1.set_value(3);
        die2.set_value(4);
        roll.roll_dice();
        REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::natural);
    }
    SECTION("Craps outcome") {
        die1.set_value(1);
        die2.set_value(1);
        roll.roll_dice();
        REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::craps);
    }
    SECTION("Point outcome") {
        die1.set_value(4);
        die2.set_value(2);
        roll.roll_dice();
        REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::point);
    }
}

TEST_CASE("PointPhase get outcomes", "[PointPhase]") {
    Die die1, die2;
    Roll roll(die1, die2);

    SECTION("Point outcome") {
        PointPhase pointPhase(8);
        die1.set_value(5);
        die2.set_value(3);
        roll.roll_dice();
        REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::point);
    }
    SECTION("Point outcome") {
        PointPhase pointPhase(5);
        die1.set_value(4);
        die2.set_value(3);
        roll.roll_dice();
        REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::seven_out);
    }
    SECTION("Point outcome") {
        PointPhase pointPhase(6);
        die1.set_value(3);
        die2.set_value(2);
        roll.roll_dice();
        REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::nopoint);
    }
}