#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "src/calculations.hpp"
#include "src/vector3d.hpp"

TEST_CASE("Example Test Case") {
    REQUIRE(10 == 10);
}

TEST_CASE("Calculations::CalculatePositionAfterMs() returns correct values") {
    auto calc = Calculations();
    REQUIRE(calc.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(0, 0, 0), 500, 500) == Vector3D(2, 3, 5));
    REQUIRE(calc.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(2, 0, 0), 500, 500) == Vector3D(4, 3, 5));
    REQUIRE(calc.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(0, 2, 0), 500, 500) == Vector3D(2, 5, 5));
    REQUIRE(calc.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(0, 0, 2), 500, 500) == Vector3D(2, 3, 7));
    REQUIRE(calc.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(1, 0, 0), 500, 0) == Vector3D(0, 0, 0));
    REQUIRE(calc.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(1, 0, 0), 1000, 500) == Vector3D(4, 3, 5));
    REQUIRE(calc.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(1, 0, 0), 500, 1000) == Vector3D(3, 3, 5));
    REQUIRE(calc.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(2, 0, 0), 500, 1000) == Vector3D(3, 3, 5));
}
