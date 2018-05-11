#include "object-trajectory-predictor.hpp"

ObjectTrajectoryPredictor::ObjectTrajectoryPredictor():
        position(0, 0, 0)
    {}

Vector3D ObjectTrajectoryPredictor::getPosition(){
    return position;
}
 

 Vector3D ObjectTrajectoryPredictor::getSpeed(const Vector3D & pos_1, 
        const Vector3D & pos_2, const int32_t & timeMs) {
    return Vector3D(
        ((pos_2.getX() - pos_1.getX()) * 1000) / timeMs,
        ((pos_2.getY() - pos_1.getY()) * 1000) / timeMs,
        ((pos_2.getZ() - pos_1.getZ()) * 1000) / timeMs
    );
 }