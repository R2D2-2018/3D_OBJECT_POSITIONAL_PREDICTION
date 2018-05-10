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