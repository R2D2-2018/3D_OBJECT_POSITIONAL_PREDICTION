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

    /**
     * @brief
     * 
     * This function calculates the average speed between two positions.
     * 
     * @param[in] Two Vector3D positions and the time difference in ms which is > 0.
     * @return The average speed of the object between the given positions.
     */
    Vector3D getSpeed(const Vector3D & position_1, const Vector3D & position_2, 
    const int32_t & time_ms);
    

};


#endif // OBJECTTRAJECTORYPREDICTOR_HPP