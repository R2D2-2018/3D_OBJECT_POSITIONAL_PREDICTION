/**
 * @file
 * @brief     Vector3D is a datatype that represents a point in a 3D world.
 * It consists of integers coordinates x, y and z.
 * @author    Max Beunk & Daniel van Vliet
 * @license   See LICENSE
 */

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include <stdint.h>

namespace PositionPrediction
{
class Vector3D {
  private:
    int32_t x;
    int32_t y;
    int32_t z;

  public:
    Vector3D(int32_t xcoord, int32_t ycoord, int32_t zcoord) : x(xcoord), y(ycoord), z(zcoord){};

    Vector3D() : x(0), y(0), z(0){};
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
    void setX(const int32_t &xcoord) {
        x = xcoord;
    }

    /**
     * @brief Sets y to new value.
     *
     * @param[in] int32_t: new y
     */
    void setY(const int32_t &ycoord) {
        y = ycoord;
    }

    /**
     * @brief Sets z to new value.
     *
     * @param[in] int32_t: new z
     */
    void setZ(const int32_t &zcoord) {
        z = zcoord;
    }

    /**
     * @brief += operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns the sum as this vector.
     */
    Vector3D &operator+=(const Vector3D &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    /**
     * @brief -= operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns the difference as this vector.
     */
    Vector3D &operator-=(const Vector3D &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    /**
     * @brief *= operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns the multiplied number as this vector.
     */
    Vector3D &operator*=(const Vector3D &rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }

    /**
     * @brief /= operator
     *
     * The method checks if the rhs has an attribute that is 0. If so, to prevent division by 0, it returns this vector instead of
     * calculating.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns the multiplied number as this vector.
     */
    Vector3D &operator/=(const Vector3D &rhs) {
        if (rhs.x == 0 || rhs.y == 0 || rhs.z == 0) {
            return *this;
        }
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        return *this;
    }

    /**
     * @brief == operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns if the rhs vector is equal to this vector.
     */
    bool operator==(const Vector3D &rhs) const {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    /**
     * @brief == operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns if the rhs vector is not equal to this vector.
     */
    bool operator!=(const Vector3D &rhs) const {
        return x != rhs.x || y != rhs.y || z != rhs.z;
    }

    /**
     * @brief + operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns the sum vector of rhs and this vector.
     */

    Vector3D operator+(const Vector3D &rhs) const {
        return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    /**
     * @brief - operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns the difference vector of rhs and this vector.
     */

    Vector3D operator-(const Vector3D &rhs) const {
        return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    /**
     * @brief * operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns the multiplied vector of rhs and this vector.
     */

    Vector3D operator*(const Vector3D &rhs) const {
        return Vector3D(x * rhs.x, y * rhs.y, z * rhs.z);
    }

    /**
     * @brief / operator.
     *
     * @param[in] Vector3D: rhs.
     *
     * returns the divided vector of rhs and this vector.
     */

    Vector3D operator/(const Vector3D &rhs) const {
        if (rhs.x != 0 && rhs.y != 0 && rhs.z != 0) {
            return Vector3D(x / rhs.x, y / rhs.y, z / rhs.z);
        }
        return Vector3D();
    }
};
}

#endif // VECTOR3D_HPP