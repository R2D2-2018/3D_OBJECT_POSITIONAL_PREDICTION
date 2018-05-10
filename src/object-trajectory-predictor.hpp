#ifndef OBJECTTRAJECTORYPREDICTOR_HPP
#define OBJECTTRAJECTORYPREDICTOR_HPP

#include "vector3d.hpp"

class ObjectTrajectoryPredictor {
private:
    Vector3D position;
public:
    ObjectTrajectoryPredictor();

    Vector3D getPosition();

};



#endif // OBJECTTRAJECTORYPREDICTOR_HPP