#include "wrap-hwlib.hpp"
#include "object-trajectory-predictor.hpp"


int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Hello world!" << hwlib::endl;

    auto predictor = ObjectTrajectoryPredictor();
    hwlib::cout << "x: " << predictor.getPosition().getX() 
    << " y: " << predictor.getPosition().getY() 
    << " z: " << predictor.getPosition().getZ() << hwlib::endl;

    return 0;
}
