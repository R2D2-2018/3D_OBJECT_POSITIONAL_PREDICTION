/**
 * @file
 * @brief     This file contains the ObjectTrajectoryPredictor, it is the main class of the module ObjectPositionalPrediction.
 *
 * @author    Max Beunk, Daniel van Vliet & Bendeguz Toth
 * @license   See LICENSE
 */

#ifndef OBJECTTRAJECTORYPREDICTOR_HPP
#define OBJECTTRAJECTORYPREDICTOR_HPP

#include "object_data.hpp"
#include "vector3d.hpp"
#include <array>
#include <math.h>

template <int N>
class ObjectTrajectoryPredictor {
  private:
    std::array<ObjectData, N> objectSampleData;

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
    Vector3D calculateSpeed(const Vector3D &pos_1, const Vector3D &pos_2, const int32_t &timeMs) {
        if (timeMs > 0) {
            return Vector3D(((pos_2.getX() - pos_1.getX()) * 1000) / timeMs, ((pos_2.getY() - pos_1.getY()) * 1000) / timeMs,
                            ((pos_2.getZ() - pos_1.getZ()) * 1000) / timeMs);
        } else {
            return Vector3D(0, 0, 0);
        }
    }

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

    Vector3D calculatePositionAfterMs(Vector3D position, Vector3D speed, uint32_t ms, Vector3D acceleration) {
        int x, y, z;
        x = position.getX() + speed.getX() + 0.5 * acceleration.getX() * pow(int(ms) / 1000, 2);
        y = position.getY() + speed.getY() + 0.5 * acceleration.getY() * pow(int(ms) / 1000, 2);
        z = position.getZ() + speed.getZ() + 0.5 * acceleration.getZ() * pow(int(ms) / 1000, 2);
        Vector3D newLocation = Vector3D(x, y, z);
        return newLocation;
    }

    /**
     * @brief calculates the acceleration of the object
     *
     * This function calculates the acceleration of the asked object
     *
     * @param[in] objectId : the object id as integer
     */
    Vector3D calculateAcceleration(uint8_t objectId) {
        objectSampleData[objectId].setAcceleration(objectSampleData[objectId].getSpeed(0) - objectSampleData[objectId].getSpeed(1));
        return objectSampleData[objectId].getAcceleration();
    }

  public:
    ObjectTrajectoryPredictor(){};

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
    void addSample(Vector3D newPosition, uint8_t objectId, uint32_t delayMs) {
        if (objectId < objectSampleData.size()) {
            objectSampleData[objectId].addSample(newPosition, delayMs);

            objectSampleData[objectId].setSpeed(
                calculateSpeed(objectSampleData[objectId].getPosition(1), objectSampleData[objectId].getPosition(0), delayMs));
        }
    }

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
    Vector3D predictPosition(uint8_t objectId, uint32_t ms) {
        if (objectId < objectSampleData.size()) {
            if (ms != 0) {
                Vector3D acceleration = calculateAcceleration(objectId);
                return calculatePositionAfterMs(objectSampleData[objectId].getPosition(0), objectSampleData[objectId].getSpeed(0),
                                                ms, acceleration);
            }
            return objectSampleData[objectId].getPosition(0);
        }
        return Vector3D();
    }

    /**
     * @brief a getter for speed.
     *
     * This function returns the latest speed for the given objectID.
     *
     * @param[in] objectId : the object id as integer
     *
     * @return A Vector3D as speed of the object.
     */
    Vector3D getSpeed(uint8_t objectId) {
        if (objectId < objectSampleData.size()) {
            return objectSampleData[objectId].getSpeed(0);
        }
        return Vector3D();
    }

    /**
     * @brief clears internal samples.
     *
     * This function clears the stored samples for the given objectID
     *
     * @param[in] objectId : the object id as integer
     */
    void clearSamples(uint8_t objectId) {
        if (objectId < objectSampleData.size()) {
            objectSampleData[objectId].clearSamples();
        }
    }
};

#endif // OBJECTTRAJECTORYPREDICTOR_HPP