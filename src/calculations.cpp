#include "calculations.hpp"
#include "wrap-hwlib.hpp"

Calculations::Calculations(){
}
Vector3D Calculations::calculatePositionAfterMs(Vector3D position, Vector3D speed, int ms, int measurementDelay){
    int x, y, z;
    x = position.getX() + (speed.getX() * (ms / measurementDelay));
    y = position.getY();
    z = position.getZ();
    Vector3D newLocation =  Vector3D(x, y, z);
    return newLocation;
}