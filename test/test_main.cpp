#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "object_trajectory_predictor.hpp"
#include "vector3d.hpp"

TEST_CASE("ObjectTrajectoryPredictor positionPrediction test cases") {
    auto testPredictor = PositionPrediction::ObjectTrajectoryPredictor<1>();
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 0, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 0, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(10, 2, 5), 0, 100);
    REQUIRE(testPredictor.predictPosition(0, 0) == PositionPrediction::Vector3D(10, 2, 5));
    REQUIRE(testPredictor.predictPosition(0, 900) == PositionPrediction::Vector3D(110, 22, 55));

    testPredictor.addSample(PositionPrediction::Vector3D(15, 5, 9), 0, 50);
    REQUIRE(testPredictor.predictPosition(0, 0) == PositionPrediction::Vector3D(15, 5, 9));
    REQUIRE(testPredictor.predictPosition(0, 200) == PositionPrediction::Vector3D(115, 65, 89));

    testPredictor.addSample(PositionPrediction::Vector3D(23, 7, 15), 0, 50);
    REQUIRE(testPredictor.predictPosition(0, 1000) == PositionPrediction::Vector3D(213, 37, 155));

    testPredictor = PositionPrediction::ObjectTrajectoryPredictor<1>();
    testPredictor.addSample(PositionPrediction::Vector3D(12, 12, 12), 0, 100);
    REQUIRE(testPredictor.predictPosition(0, 100) == PositionPrediction::Vector3D());
    testPredictor.addSample(PositionPrediction::Vector3D(12, 12, 12), 0, 100);
    REQUIRE(testPredictor.predictPosition(0, 100) == PositionPrediction::Vector3D());
    REQUIRE(testPredictor.predictPosition(0, 1000) == PositionPrediction::Vector3D());
}

TEST_CASE("ObjectTrajectoryPredictor clearSamples") {
    auto testPredictor = PositionPrediction::ObjectTrajectoryPredictor<1>();
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 0, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 0, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(10, 2, 5), 0, 1000);
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D(10, 2, 5));
    testPredictor.addSample(PositionPrediction::Vector3D(15, 2, 5), 0, 1000);
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D(5, 0, 0));
    testPredictor.clearSamples(0);
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D(0, 0, 0));
    testPredictor.addSample(PositionPrediction::Vector3D(12, 12, 12), 0, 100);
    REQUIRE(testPredictor.predictPosition(0, 100) == PositionPrediction::Vector3D());
}

TEST_CASE("ObjectTrajectoryPredictor speed test cases") {
    auto testPredictor = PositionPrediction::ObjectTrajectoryPredictor<1>();
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D());
    REQUIRE(testPredictor.predictPosition(0, 1) == PositionPrediction::Vector3D());
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 0, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 0, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(10, 0, 0), 0, 1000);
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D(10, 0, 0));
    testPredictor.addSample(PositionPrediction::Vector3D(20, 10, 5), 0, 500);
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D(20, 20, 10));
    testPredictor.addSample(PositionPrediction::Vector3D(50, 50, 0), 0, 1000);
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D(30, 40, -5));
    testPredictor.addSample(PositionPrediction::Vector3D(60, 55, 2), 0, 250);
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D(40, 20, 8));
}

TEST_CASE("ObjectTrajectoryPredictor multiple objects testing") {
    auto testPredictor = PositionPrediction::ObjectTrajectoryPredictor<3>();
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 1, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 1, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(10, 30, 40), 1, 1000);
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 2, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 2, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(20, 70, 60), 2, 1000);
    REQUIRE(testPredictor.getSpeed(0) == PositionPrediction::Vector3D(0, 0, 0));
    REQUIRE(testPredictor.getSpeed(1) == PositionPrediction::Vector3D(10, 30, 40));
    REQUIRE(testPredictor.getSpeed(2) == PositionPrediction::Vector3D(20, 70, 60));

    REQUIRE(testPredictor.predictPosition(0, 100) == PositionPrediction::Vector3D(0, 0, 0));
    REQUIRE(testPredictor.predictPosition(1, 100) == PositionPrediction::Vector3D(20, 60, 80));
    REQUIRE(testPredictor.predictPosition(2, 100) == PositionPrediction::Vector3D(40, 140, 120));

    auto testPredictor2 = PositionPrediction::ObjectTrajectoryPredictor<4>();
    testPredictor2.addSample(PositionPrediction::Vector3D(0, 0, 0), 3, 0);
    testPredictor2.addSample(PositionPrediction::Vector3D(0, 0, 0), 3, 0);
    testPredictor2.addSample(PositionPrediction::Vector3D(20, 10, 10), 3, 1000);
    REQUIRE(testPredictor2.getSpeed(0) == PositionPrediction::Vector3D(0, 0, 0));
    REQUIRE(testPredictor2.getSpeed(1) == PositionPrediction::Vector3D(0, 0, 0));
    REQUIRE(testPredictor2.getSpeed(2) == PositionPrediction::Vector3D(0, 0, 0));
}

TEST_CASE("ObjectTrajectoryPredictor predictPosition") {
    auto testPredictor = PositionPrediction::ObjectTrajectoryPredictor<1>();

    testPredictor.addSample(PositionPrediction::Vector3D(0, 0, 0), 0, 0);
    testPredictor.addSample(PositionPrediction::Vector3D(10, 8, 0), 0, 1000);
    testPredictor.addSample(PositionPrediction::Vector3D(15, 17, 2), 0, 1000);

    auto prediction = testPredictor.predictPosition(0, 1000);
    REQUIRE(prediction.getX() == 17);
    REQUIRE(prediction.getY() == 26);
    REQUIRE(prediction.getZ() == 5);

    prediction = testPredictor.predictPosition(0, 2000);
    REQUIRE(prediction.getX() == 10);
    REQUIRE(prediction.getY() == 28);
    REQUIRE(prediction.getZ() == 8);

    prediction = testPredictor.predictPosition(0, 3000);
    REQUIRE(prediction.getX() == -2);
    REQUIRE(prediction.getY() == 30);
    REQUIRE(prediction.getZ() == 13);

    prediction = testPredictor.predictPosition(0, 4000);
    REQUIRE(prediction.getX() == -20);
    REQUIRE(prediction.getY() == 34);
    REQUIRE(prediction.getZ() == 20);
}

TEST_CASE("PositionPrediction::Vector3D operator== and operator !=") {
    auto vector_1 = PositionPrediction::Vector3D(1, 2, 3);
    auto vector_2 = PositionPrediction::Vector3D(1, 2, 3);
    REQUIRE(vector_1 == vector_2);
    REQUIRE(vector_1 != PositionPrediction::Vector3D(2, 2, 3));
}
TEST_CASE("PositionPrediction::Vector3D operator+=, operator-=, operator*=, operator/=") {
    auto vector_1 = PositionPrediction::Vector3D(1, 2, 3);
    vector_1 += PositionPrediction::Vector3D(1, 2, 3);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(2, 4, 6));
    vector_1 += PositionPrediction::Vector3D(-1, -2, -3);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(1, 2, 3));

    vector_1 *= PositionPrediction::Vector3D(10, 5, 3);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(10, 10, 9));
    vector_1 *= PositionPrediction::Vector3D(-1, -2, -3);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(-10, -20, -27));

    auto vector_2 = PositionPrediction::Vector3D(0, 0, 0);
    vector_2 -= PositionPrediction::Vector3D(5, 10, 2);
    REQUIRE(vector_2 == PositionPrediction::Vector3D(-5, -10, -2));
    vector_2 -= PositionPrediction::Vector3D(-11, -16, -8);
    REQUIRE(vector_2 == PositionPrediction::Vector3D(6, 6, 6));

    vector_1 = PositionPrediction::Vector3D(5, 5, 5);
    vector_1 /= PositionPrediction::Vector3D(5, 5, 5);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(1, 1, 1));
    vector_1 /= PositionPrediction::Vector3D();
    REQUIRE(vector_1 == PositionPrediction::Vector3D(1, 1, 1));
    vector_1 /= PositionPrediction::Vector3D(-1, 1, -1);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(-1, 1, -1));
}

TEST_CASE("PositionPrediction::Vector3D operator+, operator-, operator*, operator/") {
    auto vector_1 = PositionPrediction::Vector3D(0, 0, 0) + PositionPrediction::Vector3D(1, 2, 3);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(1, 2, 3));

    vector_1 = PositionPrediction::Vector3D(10, 15, 20) - PositionPrediction::Vector3D(15, 20, 10);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(-5, -5, 10));

    auto vector_2 = PositionPrediction::Vector3D(1, 2, 3) * PositionPrediction::Vector3D(5, 10, 20);
    REQUIRE(vector_2 == PositionPrediction::Vector3D(5, 20, 60));

    vector_1 = PositionPrediction::Vector3D(10, 20, 30) / PositionPrediction::Vector3D(2, 5, 6);
    REQUIRE(vector_1 == PositionPrediction::Vector3D(5, 4, 5));
}