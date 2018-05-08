#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
class Vector3D {
  private:
    int x;
    int y;
    int z;

  public:
    Vector3D(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    int getX() {
        return this.x;
    }
    int getY() {
        return this.y;
    }
    int getZ() {
        return this.z;
    }
    int setX(int x) {
        this.x = x;
    }
    int setY(int y) {
        this.y = y;
    }
    int setZ(int z) {
        this.z = z;
    }
};

#endif // VECTOR3D_HPP