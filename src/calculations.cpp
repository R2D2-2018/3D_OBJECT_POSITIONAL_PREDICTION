#include "calculations.hpp"
#include "wrap-hwlib.hpp"

Calculations::Calculations() {
}
Vector3D Calculations::calculatePositionAfterMs(Vector3D position, Vector3D speed, uint32_t ms, uint32_t measurementDelay) {
    int x, y, z;
    if (measurementDelay > 0) {
        x = position.getX() + (speed.getX() * (ms / measurementDelay));
        y = position.getY() + (speed.getY() * (ms / measurementDelay));
        z = position.getZ() + (speed.getZ() * (ms / measurementDelay));
        Vector3D newLocation = Vector3D(x, y, z);
        return newLocation;
    } else {
        return Vector3D(0, 0, 0);
    }
}