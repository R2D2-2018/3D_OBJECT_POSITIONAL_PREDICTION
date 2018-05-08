#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
class Vector3D {
  private:
    int X;
    int Y;
    int Z;
    int timeMs;

  public:
    Vector3D(int x, int y, int z, int ms): X(x), Y(y), Z(z), timeMs(ms){};

    int getX() {
        return X;
    }
    int getY() {
        return Y;
    }
    int getZ() {
        return Z;
    }
    int getTimeMs(){
        return timeMs;
    }
    void setX(int x) {
        X = x;
    }
    void setY(int y) {
        Y= y;
    }
    void setZ(int z) {
        Z = z;
    }
    void setTimeMs(int ms){
        timeMs = ms;
    }
};

#endif // VECTOR3D_HPP