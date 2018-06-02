#include "object_trajectory_predictor.hpp"

ObjectTrajectoryPredictor::ObjectTrajectoryPredictor() {
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
    objectSampleData[objectId].addSample(newPosition, delayMs);

    objectSampleData[objectId].setSpeed(
        calculateSpeed(objectSampleData[objectId].getPosition(1), objectSampleData[objectId].getPosition(0), delayMs));
}

Vector3D ObjectTrajectoryPredictor::predictPosition(uint8_t objectId, uint32_t ms) {
    if (ms != 0) {
        return calculatePositionAfterMs(objectSampleData[objectId].getPosition(0), objectSampleData[objectId].getSpeed(), ms);
    }
    return objectSampleData[objectId].getPosition(0);
}

Vector3D ObjectTrajectoryPredictor::getSpeed(uint8_t objectId) {
    return objectSampleData[objectId].getSpeed();
}

void ObjectTrajectoryPredictor::clearSamples(uint8_t objectId) {
}