#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "src/object-trajectory-predictor.hpp"

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

TEST_CASE("ObjectTrajectoryPredictor getPosition() returns a Vector3D") {
    auto tempPredictor = ObjectTrajectoryPredictor();
    
    REQUIRE(temp_predictor.getPosition().getX() == 0);
}

TEST_CASE( "ObjectTrajectoryPredictor calculateSpeed() Test Case" ) {
    const auto pos_1 = Vector3D(0, 0, 0);
    const auto pos_2 = Vector3D(10, 15, 20);
    auto speed = predictor.calculateSpeed(pos_1, pos_2, 1500);
    REQUIRE(speed.getX() == 6)
    REQUIRE(speed.getY() == 10)
    REQUIRE(speed.getZ() == 13)

    pos_1 = Vector3D(20, 15, 10);
    pos_2 = Vector3D(10, 15, 20);
    speed = predictor.calculateSpeed(pos_1, pos_2, 500);
    REQUIRE(speed.getX() == -20)
    REQUIRE(speed.getY() == 0)
    REQUIRE(speed.getZ() == 20)

}