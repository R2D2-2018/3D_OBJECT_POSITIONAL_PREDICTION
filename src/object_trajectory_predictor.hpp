#ifndef OBJECTTRAJECTORYPREDICTOR_HPP
#define OBJECTTRAJECTORYPREDICTOR_HPP

#include "vector3d.hpp"
#include <array>

/**
 * @file
 * @brief     This file contains the ObjectTrajectoryPredictor, it is the main class of the module ObjectPositionalPrediction.
 *
 * @author    Max Beunk & Daniel van Vliet
 * @license   See LICENSE
 */

class ObjectTrajectoryPredictor {
  private:
    std::array<Vector3D, 10> positions;
    std::array<int, 10> measurementDelay;
    Vector3D speed;

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

    /**
     * @brief This method adds a new sample and updates speed.
     *
     *  This method adds a new sample to the internal stored sample array and calculates
     *  the latest speed with the new sample array.
     *  This function shifts the new sample into the position and measurementDelay arrays.
     *  The position and delay are inserted at the end of the arrays. This is using the First in first out principle.
     *  This method is assuming the sample size of the arrays is 10
     *
     *
     * @param[in] a new sample as vector3D, the object id and the delay between last sample in milliseconds.
     */
    void addSample(Vector3D newPosition, uint8_t objectId, uint32_t delayMs);

    /**
     * @brief
     *
     * This function predicts the position after given ms, using the interal stored samples.
     * If given time is 0, it will return the last inserted sample position.
     *
     * @param[in] objectId as int, ms as int
     * The time for next prediction needs to be the time since last added sample.
     * @return A Vector3D containing the predicted position of the object
     */
    Vector3D predictPosition(uint8_t objectId, uint32_t ms);

    /**
     * @brief
     *
     * This function returns the latest speed for the given objectID.
     *
     * @param[in] objectId as int
     * The time for next prediction needs to be the time since last added sample.
     * @return A Vector3D as speed of the object.
     */
    Vector3D getSpeed(uint8_t objectId);

    /**
     * @brief
     *
     * This function clears the stored samples for the given objectID
     *
     * @param[in] objectId as int
     */
    void clearSamples(uint8_t objectId);
};

#endif // OBJECTTRAJECTORYPREDICTOR_HPP