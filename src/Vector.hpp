#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP
#include "wrap-hwlib.hpp"
class Vector{
    private:
    int x;
    int y;
    int z;
    public:
    Vector(int x, int y, int z){
        this.x = x;
        this.y = y;
        this.z = z;
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
    int setX(int x){
        this.x = x;
    }
    int setY(int y){
        this.y = y;
    }
    int setZ(int z){
        this.z = z;
    }
}

#endif // CALCULATION_HPP