#ifndef OBJECTDATA_HPP
#define OBJECTDATA_HPP
#include "vector3d.hpp"
#include <array>

class ObjectData {
  private:
    std::array<Vector3D, 10> positions;
    std::array<int, 10> measurementDelay;
    Vector3D speed;

  public:
    ObjectData();

    void addSample(Vector3D newPosition, uint32_t delayMs);

    Vector3D getPosition(const uint8_t &index);

    void setSpeed(const Vector3D &newSpeed);
    Vector3D getSpeed();

    void clearSamples();
};

#endif