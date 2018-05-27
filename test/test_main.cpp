#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "object_trajectory_predictor.hpp"
#include "vector3d.hpp"

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
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(1, 0, 0), 500) == Vector3D(2, 3, 5));
    REQUIRE(tempPredictor.calculatePositionAfterMs(Vector3D(2, 3, 5), Vector3D(2, 0, 0), 500) == Vector3D(3, 3, 5));
}

TEST_CASE("ObjectTrajectoryPredictor calculateSpeed() Test Case") {
    auto tempPredictor = ObjectTrajectoryPredictor();
    auto pos_1 = Vector3D(0, 0, 0);
    auto pos_2 = Vector3D(10, 15, 20);
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

    REQUIRE(tempPredictor.getPosition(0) == pos1);
    REQUIRE(tempPredictor.getPosition(1) == pos2);
    REQUIRE(tempPredictor.getPosition(2) == pos3);
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

TEST_CASE("Vector3D operator== and operator !=") {
    auto vector_1 = Vector3D(1, 2, 3);
    auto vector_2 = Vector3D(1, 2, 3);
    REQUIRE(vector_1 == vector_2);
    REQUIRE(vector_1 != Vector3D(2, 2, 3));
}
TEST_CASE("Vector3D operator+=, operator-=, operator*=, operator/=") {
    auto vector_1 = Vector3D(1, 2, 3);
    vector_1 += Vector3D(1, 2, 3);
    REQUIRE(vector_1 == Vector3D(2, 4, 6));
    vector_1 += Vector3D(-1, -2, -3);
    REQUIRE(vector_1 == Vector3D(1, 2, 3));

    vector_1 *= Vector3D(10, 5, 3);
    REQUIRE(vector_1 == Vector3D(10, 10, 9));
    vector_1 *= Vector3D(-1, -2, -3);
    REQUIRE(vector_1 == Vector3D(-10, -20, -27));

    auto vector_2 = Vector3D(0, 0, 0);
    vector_2 -= Vector3D(5, 10, 2);
    REQUIRE(vector_2 == Vector3D(-5, -10, -2));
    vector_2 -= Vector3D(-11, -16, -8);
    REQUIRE(vector_2 == Vector3D(6, 6, 6));

    vector_1 = Vector3D(5, 5, 5);
    vector_1 /= Vector3D(5, 5, 5);
    REQUIRE(vector_1 == Vector3D(1, 1, 1));
    vector_1 /= Vector3D();
    REQUIRE(vector_1 == Vector3D(1, 1, 1));
    vector_1 /= Vector3D(-1, 1, -1);
    REQUIRE(vector_1 == Vector3D(-1, 1, -1));
}

TEST_CASE("Vector3D operator+, operator-, operator*, operator/") {
    auto vector_1 = Vector3D(0, 0, 0) + Vector3D(1, 2, 3);
    REQUIRE(vector_1 == Vector3D(1, 2, 3));

    vector_1 = Vector3D(10, 15, 20) - Vector3D(15, 20, 10);
    REQUIRE(vector_1 == Vector3D(-5, -5, 10));

    auto vector_2 = Vector3D(1, 2, 3) * Vector3D(5, 10, 20);
    REQUIRE(vector_2 == Vector3D(5, 20, 60));

    vector_1 = Vector3D(10, 20, 30) / Vector3D(2, 5, 6);
    REQUIRE(vector_1 == Vector3D(5, 4, 5));
}