#include "object_data.hpp"

ObjectData::ObjectData() {
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
}

Vector3D ObjectData::getPosition(const int &index) {
    return positions[index];
}

Vector3D ObjectData::getSpeed() {
    return speed;
}

void ObjectData::setSpeed(const Vector3D &newSpeed) {
    speed = newSpeed;
}

void ObjectData::clearSamples() {
}