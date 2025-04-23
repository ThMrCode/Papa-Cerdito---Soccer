#include <BTControl.h>

void setup() {
    DriverMotor::start();
    BTControl::start();
}

void loop() {
    BTControl::loop();
}
 