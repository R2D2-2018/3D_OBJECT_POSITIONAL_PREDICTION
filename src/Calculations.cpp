#include "Calculations.hpp"
#include "wrap-hwlib.hpp"

Calculations::Calculations(){
}
Vector3D Calculations::calculatePositionAfterMs(Vector3D position, Vector3D speed, int ms){
    int x, y, z;
    x = position.getX() + (speed.getX() * (ms/speed.getTimeMs()));
    y = position.getY();
    z = position.getZ();
    Vector3D newLocation =  Vector3D(x, y, z, 0);
    return newLocation;
}