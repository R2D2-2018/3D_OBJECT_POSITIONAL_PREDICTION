#include "object_data.hpp"

ObjectData::ObjectData():
    numberOfSamples(0)
    {
    for (unsigned int i = 0; i < measurementDelay.size(); ++i) {
        measurementDelay[i] = 0;
    }
}

void ObjectData::addSample(Vector3D newPosition, uint32_t delayMs) {
    for (unsigned int i = positions.size() - 1; i > 0; --i) {
        positions[i] = positions[i - 1];
        measurementDelay[i] = measurementDelay[i - 1];
    }

    positions[0] = newPosition;
    measurementDelay[0] = delayMs;
    numberOfSamples++;
}

Vector3D ObjectData::getPosition(const uint32_t &index) {
    if (index < positions.size()) {
        return positions[index];
    }
    return Vector3D();
}

Vector3D ObjectData::getSpeed(uint32_t index) {
    return speed[index];
}

void ObjectData::setSpeed(const Vector3D &newSpeed) {
    for (unsigned int i = speed.size() - 1; i > 0; --i) {
        speed[i] = speed[i - 1];
    }
    speed[0] = newSpeed;
}

void ObjectData::clearSamples() {
    for (int i = 0; i < positions.size(); ++i) {
        positions[i] = Vector3D();
        measurementDelay[i] = 0;
        speed[i] = Vector3D();
    }
    acceleration = Vector3D();
    numberOfSamples = 0;
}

void ObjectData::setAcceleration(Vector3D newAcceleration) {
    acceleration = newAcceleration;
}

Vector3D ObjectData::getAcceleration() {
    return acceleration;
}

uint8_t ObjectData::size()
{
    return numberOfSamples;
}