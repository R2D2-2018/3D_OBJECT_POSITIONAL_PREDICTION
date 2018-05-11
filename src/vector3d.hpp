#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include <stdint.h>

/**
 * @file
 * @brief     Vector3D is a datatype that represents a point in a 3D world. 
 * It consists of integers coordinates x, y and z.
 * @author    Max Beunk & Daniel van Vliet
 * @license   See LICENSE
 */

class Vector3D {
  private:
    int32_t x;
    int32_t y;
    int32_t z;

  public:
    Vector3D(int32_t xcoord, int32_t ycoord, int32_t zcoord):
     x(xcoord), y(ycoord), z(zcoord){};

    /**
     * @brief Getter method for x.
     * 
     * @return int32_t x
     */
    int32_t getX() const {
        return x;
    }
    
    /**
     * @brief Getter method for y.
     * 
     * @return int32_t y
     */
    int32_t getY() const {
        return y;
    }


    /**
     * @brief Getter method for z.
     * 
     * @return int32_t z
     */
    int32_t getZ() const {
        return z;
    }

    /**
     * @brief Sets x to new value.
     * 
     * @param[in] int32_t: new x
     */
    void setX(const int32_t & xcoord) {
        x = xcoord;
    }

    /**
     * @brief Sets y to new value.
     * 
     * @param[in] int32_t: new y
     */
    void setY(const int32_t & ycoord) {
        y = ycoord;
    }

    /**
     * @brief Sets z to new value.
     *
     * @param[in] int32_t: new z
     */
    void setZ(const int32_t & zcoord) {
        z = zcoord;
    }
};

#endif // VECTOR3D_HPP