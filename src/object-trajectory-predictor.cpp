#include "object-trajectory-predictor.hpp"

ObjectTrajectoryPredictor::ObjectTrajectoryPredictor():
        position(0, 0, 0)
    {}

Vector3D ObjectTrajectoryPredictor::getPosition(){
    return position;
}
 