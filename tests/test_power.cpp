#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "power.hpp"

TEST_CASE("Power functions correctness") {
    REQUIRE(naivePower(2, 3) == 8);
    REQUIRE(unoptimizedDCPower(2, 3) == 8);
    REQUIRE(optimizedDCPower(2, 3) == 8);

    REQUIRE(naivePower(5, 0) == 1);
    REQUIRE(unoptimizedDCPower(5, 0) == 1);
    REQUIRE(optimizedDCPower(5, 0) == 1);

    REQUIRE(naivePower(0, 5) == 0);
    REQUIRE(unoptimizedDCPower(0, 5) == 0);
    REQUIRE(optimizedDCPower(0, 5) == 0);

    REQUIRE(optimizedDCPower(3, 4) == 81);
}