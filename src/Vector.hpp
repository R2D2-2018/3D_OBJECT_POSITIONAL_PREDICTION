#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP
#include "wrap-hwlib.hpp"
class Vector{
    private:
    int x;
    int y;
    int z;
    int timeMs; // delta for speed measurement
    public:
    Vector(int x, int y, int z, int timeMs){
        this.x = x;
        this.y = y;
        this.z = z;
        this.timeMs = timeMs; 
    }
    int getX(){
        return this.x;
    }
    int getY(){
        return this.y;
    }
    int getZ(){
        return this.z;
    }
    int getTimeMs(){
        return this.timeMs;
    }
    void setX(int x){
        this.x = x;
    }
    void setY(int y){
        this.y = y;
    }
    void setZ(int z){
        this.z = z;
    }
    void setTimeMs(int timeMs){
        this.timeMs = timeMs;
    }
}

#endif // CALCULATION_HPP