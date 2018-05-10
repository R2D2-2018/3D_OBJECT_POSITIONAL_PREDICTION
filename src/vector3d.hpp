#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include <stdint.h>

class Vector3D {
  private:
    int32_t x;
    int32_t y;
    int32_t z;

  public:
    Vector3D(int32_t xcoord, int32_t ycoord, int32_t zcoord): x(xcoord), y(ycoord), z(zcoord){};

    int32_t getX() {
        return x;
    }
    int32_t getY() {
        return y;
    }
    int32_t getZ() {
        return z;
    }
    void setX(int xcoord) {
        x = xcoord;
    }
    void setY(int ycoord) {
        y = ycoord;
    }
    void setZ(int zcoord) {
        z = zcoord;
    }
};

#endif // VECTOR3D_HPP