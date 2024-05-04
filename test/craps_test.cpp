#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

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


TEST_CASE("Test case to test roll for value 2 and 112", "[Die]") {
    Die die1, die2;
    Roll roll(die1, die2);
    roll.roll_dice();
    int result = roll.roll_value();
    REQUIRE(result >= 1);
    REQUIRE(result <= 6);
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