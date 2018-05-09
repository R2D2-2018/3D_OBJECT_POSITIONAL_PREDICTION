#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
class Vector3D {
  private:
    int x;
    int y;
    int z;

  public:
    Vector3D(int xcoord, int ycoord, int zcoord): x(xcoord), y(ycoord), z(zcoord){};

    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getZ() {
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