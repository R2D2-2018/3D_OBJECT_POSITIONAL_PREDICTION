#include "vector3D.hpp"
#include "wrap-hwlib.hpp"
class Calculations {
  private:
  public:
    Calculations();
    Vector3D calculatePositionAfterMs(Vector3D position, Vector3D speed, int ms, int measurementDelay);
};