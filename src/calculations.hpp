#include "vector3D.hpp"
#include "wrap-hwlib.hpp"

class Calculations {
  private:
  public:
    Calculations();

    /**
     * @brief
     *
     * This function calculates the new position of the object after, by user given, milliseconds
     *
     * @param[in] The current position of the object, the speed of this object, the amount of milliseconds and the delay used
     * between 2 measuring points while calculating speed
     * @return A vector object containing the new position of the object
     */
    Vector3D calculatePositionAfterMs(Vector3D position, Vector3D speed, uint32_t ms, uint32_t measurementDelay);
};