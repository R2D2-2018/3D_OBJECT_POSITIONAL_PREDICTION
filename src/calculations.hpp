#include "vector3D.hpp"
#include "wrap-hwlib.hpp"

class Calculations {
  private:
  public:
    Calculations();
    Vector3D calculatePositionAfterMs(Vector3D position, Vector3D speed, uint32_t ms, uint32_t measurementDelay);
};