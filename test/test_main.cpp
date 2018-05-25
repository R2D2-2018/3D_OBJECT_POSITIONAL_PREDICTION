#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "src/object_trajectory_predictor.hpp"
#include "src/vector3d.hpp"

TEST_CASE("Example Test Case") {
    REQUIRE(10 == 10);
}

TEST_CASE("ObjectTrajectoryPredictor::CalculatePositionAfterMs() returns correct values") {
    auto tempPredictor = ObjectTrajectoryPredictor();
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(0, 0, 0), 500) == Vector3D(2, 3, 5));
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(2, 0, 0), 500) == Vector3D(3, 3, 5));
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(0, 2, 0), 500) == Vector3D(2, 4, 5));
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(0, 0, 2), 500) == Vector3D(2, 3, 5));
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(1, 0, 0), 500) == Vector3D(4, 3, 5));
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(1, 0, 0), 1000) == Vector3D(3, 3, 5));
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(1, 0, 0), 500) == Vector3D(4, 3, 5));
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(2, 0, 0), 500) == Vector3D(6, 3, 5));
}
// TEST_CASE("ObjectTrajectoryPredictor getPosition() returns a Vector3D") {
//     auto tempPredictor = ObjectTrajectoryPredictor();

//     REQUIRE(tempPredictor.getPosition().getX() == 0);
// }

TEST_CASE("ObjectTrajectoryPredictor calculateSpeed() Test Case") {
    auto tempPredictor = ObjectTrajectoryPredictor();
    const auto pos_1 = Vector3D(0, 0, 0);
    const auto pos_2 = Vector3D(10, 15, 20);
    auto speed = tempPredictor.calculateSpeed(pos_1, pos_2, 1500);
    REQUIRE(speed.getX() == 6);
    REQUIRE(speed.getY() == 10);
    REQUIRE(speed.getZ() == 13);

    pos_1 = Vector3D(20, 15, 10);
    pos_2 = Vector3D(10, 15, 20);
    speed = tempPredictor.calculateSpeed(pos_1, pos_2, 500);
    REQUIRE(speed.getX() == -20);
    REQUIRE(speed.getY() == 0);
    REQUIRE(speed.getZ() == 20);

    speed = tempPredictor.calculateSpeed(pos_1, pos_2, 0);
    REQUIRE(speed.getX() == 0);
    REQUIRE(speed.getY() == 0);
    REQUIRE(speed.getZ() == 0);
}

TEST_CASE("ObjectTrajectoryPredictor setSample is saving positions in array") {
    auto tempPredictor = ObjectTrajectoryPredictor();
    auto pos1 = Vector3D(0, 0, 0);
    auto pos2 = Vector3D(1, 2, 3);
    auto pos3 = Vector3D(3, 5, 6);

    tempPredictor.setSample(pos1);
    tempPredictor.setSample(pos2);
    tempPredictor.setSample(pos3);

    REQUIRE(getPosition(0) == pos1);
    REQUIRE(getPosition(1) == pos2);
    REQUIRE(getPosition(2) == pos3);
}

TEST_CASE("ObjectTrajectoryPredictor setSample cant overflow") {
    auto tempPredictor = ObjectTrajectoryPredictor();
    auto pos = Vector3D(0, 0, 0);
    bool check[13];

    for (int i = 0; i < 12; i++) {
        check[i] = tempPredictor.setSample(pos);
    }

    REQUIRE(check[9] == 0);
    REQUIRE(check[10] == 1);
    REQUIRE(check[11] == 1);
}
