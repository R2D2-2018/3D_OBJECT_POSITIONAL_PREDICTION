#include "object_trajectory_predictor.hpp"
#include "wrap-hwlib.hpp"

ObjectTrajectoryPredictor::ObjectTrajectoryPredictor() {
    for (int i = 0; i < 10; ++i) {
        measurementDelay[i] = 0;
    }
}

Vector3D ObjectTrajectoryPredictor::calculateSpeed(const Vector3D &pos_1, const Vector3D &pos_2, const int32_t &timeMs) {

    if (timeMs > 0) {
        return Vector3D(((pos_2.getX() - pos_1.getX()) * 1000) / timeMs, ((pos_2.getY() - pos_1.getY()) * 1000) / timeMs,
                        ((pos_2.getZ() - pos_1.getZ()) * 1000) / timeMs);
    } else {
        return Vector3D(0, 0, 0);
    }
}

Vector3D ObjectTrajectoryPredictor::calculatePositionAfterMs(Vector3D position, Vector3D speed, uint32_t ms) {
    int x, y, z;
    x = position.getX() + ((speed.getX() * ms) / 1000);
    y = position.getY() + ((speed.getY() * ms) / 1000);
    z = position.getZ() + ((speed.getZ() * ms) / 1000);
    Vector3D newLocation = Vector3D(x, y, z);
    return newLocation;
}

void ObjectTrajectoryPredictor::addSample(Vector3D newPosition, uint8_t objectId, uint32_t delayMs) {
    for (unsigned int i = 0; i < 9; ++i) {
        positions[i] = positions[i + 1];
        measurementDelay[i] = measurementDelay[i + 1];
    }
    positions[9] = newPosition;
    measurementDelay[9] = delayMs;

    speed = calculateSpeed(positions[8], positions[9], delayMs);
}

Vector3D ObjectTrajectoryPredictor::predictPosition(uint8_t objectId, uint32_t ms) {
    if (ms != 0) {
        calculatePositionAfterMs(positions[9], speed, ms);
    }
    return positions[9];
}

Vector3D ObjectTrajectoryPredictor::getSpeed(uint8_t objectId) {
    return speed;
}

void ObjectTrajectoryPredictor::clearSamples(uint8_t objectId) {
}