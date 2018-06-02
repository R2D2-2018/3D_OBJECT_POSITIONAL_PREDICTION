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

};

#endif