#ifndef OBJECTTRAJECTORYPREDICTOR_HPP
#define OBJECTTRAJECTORYPREDICTOR_HPP

#include "vector3d.hpp"


class ObjectTrajectoryPredictor {
private:
    Vector3D position;
public:
    ObjectTrajectoryPredictor();

    /**
     * @brief
     * 
     * This function is a getter for the position of the tracked object.
     * 
     * @return The current position of the object as Vector3D.
     */
    Vector3D getPosition();

};


#endif // OBJECTTRAJECTORYPREDICTOR_HPP