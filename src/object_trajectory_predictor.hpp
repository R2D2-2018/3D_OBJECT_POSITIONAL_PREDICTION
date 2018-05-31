#ifndef OBJECTTRAJECTORYPREDICTOR_HPP
#define OBJECTTRAJECTORYPREDICTOR_HPP

#include "vector3d.hpp"

/**
 * @file
 * @brief     This file contains the ObjectTrajectoryPredictor, it is the main class of the module ObjectPositionalPrediction.
 *
 * @author    Max Beunk & Daniel van Vliet
 * @license   See LICENSE
 */

class ObjectTrajectoryPredictor {
  private:
    int positionsIndex = 0;
    Vector3D positions[10];
    int measurementDelay[10];
    Vector3D speed;
    Vector3D predictedPosition;


    /**
     * @brief
     *
     * This function calculates the average speed between two positions.
     *
     * @param[in] Two Vector3D positions and the time difference in ms which is > 0.
     * @return The average speed of the object between the given positions.
     */
    Vector3D calculateSpeed(const Vector3D &position_1, const Vector3D &position_2, const int32_t &time_ms);

    /**
     * @brief
     *
     * This function calculates the new position of the object after, by user given, milliseconds
     *
     * @param[in] The current position of the object, the speed of this object, the amount of milliseconds
     * @return A vector object containing the new position of the object
     */

    Vector3D calculatePositionAfterMs(Vector3D position, Vector3D speed, uint32_t ms);
    public:     
    ObjectTrajectoryPredictor();

    bool addSample(Vector3D newPosition, uint8_t objectId, int delay);

    Vector3D predictPosition(uint8_t objectId, uint32_t ms);

    Vector3D getSpeed(uint8_t objectId);

    void clearSamples(uint8_t objectId);
  

};

#endif // OBJECTTRAJECTORYPREDICTOR_HPP