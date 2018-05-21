#include "wrap-hwlib.hpp"
#include "object_trajectory_predictor.hpp"


int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Hello world!" << hwlib::endl;

    auto predictor = ObjectTrajectoryPredictor();
    hwlib::cout << "x: " << predictor.getPosition().getX() 
    << " y: " << predictor.getPosition().getY() 
    << " z: " << predictor.getPosition().getZ() << hwlib::endl;

    const auto pos_1 = Vector3D(20, 15, 10);
    const auto pos_2 = Vector3D(10, 15, 20);
    auto speed = predictor.calculateSpeed(pos_1, pos_2, 500);

    hwlib::cout << "Speed vector x: " << speed.getX() 
    << ", y: " << speed.getY() 
    << ", z: " << speed.getZ() << hwlib::endl;

    return 0;
}
