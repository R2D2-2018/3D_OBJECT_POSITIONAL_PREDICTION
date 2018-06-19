/**
 * @file
 * @brief     This file contains the ObjectTrajectoryPredictor, it is the main class of the module ObjectPositionalPrediction.
 *
 * @author    Max Beunk & Daniel van Vliet
 * @license   See LICENSE
 */

#ifndef OBJECTTRAJECTORYPREDICTOR_HPP
#define OBJECTTRAJECTORYPREDICTOR_HPP

#include "object_data.hpp"
#include "vector3d.hpp"
#include <array>
#include <math.h>

class ObjectTrajectoryPredictor {
  private:
    std::array<ObjectData, 3> objectSampleData;

    /**
     * @brief
     *
     * This function calculates the average speed between two positions.
     *
     * @param[in] position_1 : first position.
     * @param[in] position_2 : second position.
     * @param[in] timeMs : the time difference in ms which is > 0.
     * @return The average speed of the object between the given positions.
     */
    Vector3D calculateSpeed(const Vector3D &position_1, const Vector3D &position_2, const int32_t &timeMs);

    /**
     * @brief returns a new position from the current position, speed and time.
     *
     * This function calculates the new position of the object. The method takes
     * the previous path of the object into account when predicting, so it is
     * able to predict the new position much more accurately.
     *
     * @param[in] position : The current position of the object
     * @param[in] speed : the speed of the object
     * @param[in] ms : the amount of milliseconds to predict position for.
     * @param[in] acceleration : the acceleration of the object as Vector3D
     * @return A vector object containing the new position of the object
     */

    Vector3D calculatePositionCurvedAfterMs(Vector3D position, Vector3D speed, uint32_t ms, Vector3D acceleration);

    /**
     * @brief calculates the acceleration of the object
     *
     * This function calculates the acceleration of the asked object
     *
     * @param[in] objectId : the object id as integer
     */
    Vector3D calculateAcceleration(uint8_t objectId);

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
     * @param[in] newPosition : a new sample as vector3D
     * @param[in] objectId : the object id as integer
     * @param[in] delayMs : the delay between last sample in milliseconds.
     */
    void addSample(Vector3D newPosition, uint8_t objectId, uint32_t delayMs);

    /**
     * @brief This method returns the predicted position over a given time.
     *
     * This function predicts the position after given ms, using the interal stored samples.
     * If given time is 0, it will return the last inserted sample position.
     * The method takes the previous path of the object into account when predicting, so it is
     * able to predict the new position much more accurately.
     *
     * @param[in] objectId : the object id as integer
     * @patarm[in] ms : difference in time between last sample and desired prediction.
     * @return A Vector3D containing the predicted position of the object
     */
    Vector3D predictPositionCurved(uint8_t objectId, uint32_t ms);

    /**
     * @brief a getter for speed.
     *
     * This function returns the latest speed for the given objectID.
     *
     * @param[in] objectId : the object id as integer
     *
     * @return A Vector3D as speed of the object.
     */
    Vector3D getSpeed(uint8_t objectId);

    /**
     * @brief clears internal samples.
     *
     * This function clears the stored samples for the given objectID
     *
     * @param[in] objectId : the object id as integer
     */
    void clearSamples(uint8_t objectId);
};

#endif // OBJECTTRAJECTORYPREDICTOR_HPP