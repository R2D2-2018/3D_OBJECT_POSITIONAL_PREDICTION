#include "object-trajectory-predictor.hpp"

ObjectTrajectoryPredictor::ObjectTrajectoryPredictor():
        position(0, 0, 0)
    {}

Vector3D ObjectTrajectoryPredictor::getPosition(){
    return position;
}
 

 Vector3D ObjectTrajectoryPredictor::calculateSpeed(const Vector3D & pos_1, 
        const Vector3D & pos_2, const int32_t & timeMs) {
    return Vector3D(
        ((pos_2.getX() - pos_1.getX()) * 1000) / timeMs,
        ((pos_2.getY() - pos_1.getY()) * 1000) / timeMs,
        ((pos_2.getZ() - pos_1.getZ()) * 1000) / timeMs
    );
 }

 Vector3D ObjectTrajectoryPredictor::calculatePositionAfterMs(Vector3D position, Vector3D speed, uint32_t ms,
        uint32_t measurementDelay) {
    int x, y, z;
    if (measurementDelay > 0) {
        x = position.getX() + (speed.getX() * (ms / measurementDelay));
        y = position.getY() + (speed.getY() * (ms / measurementDelay));
        z = position.getZ() + (speed.getZ() * (ms / measurementDelay));
        Vector3D newLocation = Vector3D(x, y, z);
        return newLocation;
    } else {
        return Vector3D(0, 0, 0);
    }
 }