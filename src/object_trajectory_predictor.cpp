#include "object_trajectory_predictor.hpp"
#include "wrap-hwlib.hpp"

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

bool ObjectTrajectoryPredictor::addSample(Vector3D newPosition, uint8_t objectId, int delay) {
    if (positionsIndex < 10) {
        positions[positionsIndex] = newPosition;
        measurementDelay[positionsIndex] = delay;
        speed = calculateSpeed(positions[positionsIndex - 1], newPosition, delay);
        positionsIndex += 1;
        return 1;
    } else {
        return 0;
    }
}

Vector3D ObjectTrajectoryPredictor::predictPosition(uint8_t objectId, uint32_t ms) {
    if (ms != 0) {
        predictedPosition = calculatePositionAfterMs(positions[positionsIndex - 1], speed, ms);
    }
    return predictedPosition;
}

Vector3D ObjectTrajectoryPredictor::getSpeed(uint8_t objectId){
    return speed;
}